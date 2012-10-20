<?php

/**
 */
class FeedsIsEngineParser extends FeedsParser {
  /**
   * Implements FeedsParser::parse().
   */
  public function parse(FeedsSource $source, FeedsFetcherResult $fetcher_result) {
    $content_type = 'work';

    // Set time zone to GMT for parsing dates with strtotime().
    $tz = date_default_timezone_get();
    date_default_timezone_set('GMT');
    // Yes, using a DOM parser is a bit inefficient, but will do for now
    $xml = new SimpleXMLElement($fetcher_result->getRaw());
    $result = new FeedsParserResult();
    foreach ($xml->record as $record) {
//  we need one parser for each content type so filter on that type
      if ( trim($record->category) == $content_type ) {
        $item = array('title' => _decode_html($record->title));
        if ($record['modified']) {
          $item['modified'] = (int)$record['modified'];
        }
        if ($record->subtitle) {
          $item['subtitle'] = _decode_html($record->subtitle);
        }
        if ($record->id) {
          $item['isengine_id'] = $record->id;
        }
        if ($record->abstract) {
          $item['abstract'] = _decode_html($record->abstract);
        }
        if ($record->description) {
          $item['description'] = _decode_html($record->description);
        }
        if ($record->subcategory) {
          $item['subcategory'] = (string) $record->subcategory;
        }
        if ($record->is_recent) {
          $item['is_recent'] = 1;
        }
        if ($record->is_series) {
          $item['is_series'] = 1;
        }
        if ($record->collection_of) {
          $item['collection_of'] = _decode_html($record->collection_of);
        }
        if ($record->cost) {
          $item['cost'] = (string) $record->cost;
        }
        if ($record->year) {
          $year = $record->year;
          if ( intval($year) > 3000 ) {
            // convert the integer into epoch and then into %Y
            $year = strftime('%Y', (int)$year);
          }
          $item['year'] = (string) $year;
        }
        if ($record->is_sold) {
          $item['is_sold'] = 1;
        }
        if ($record->thank_you) {
          $item['thank_you'] = _decode_html($record->thank_you);
        }
        if ($record->media) {
          $item['materials'] = _decode_html($record->media);
        }
        if (count($record->exhibition)) {
          //  an array of exhibitions with title, venue, start and stop dates
          $exhibitions = array();
          foreach ( $record->gallery as $exhibition ) {
            $title = trim($exhibition->title);
            //  search for an exhibition with this title
            //  query
            //  SELECT nid FROM node WHERE node.title IS "$title"
          }
        }
        if (count($record->gallery)) {
          //  an array of images with caption, attribution and colour
//          error_log("Gallery items: " . count($record->gallery));
//            $item['geolocations'][$k] = new FeedsGeoTermElement($v);
//  FeedsElement > FeedsTermElement > FeedsGeoTermElement
          //  possibly create and relate media item 
          //  alternatively create imagefield item
          $images = array();
          foreach ( $record->gallery as $image ) {
            $id = intval($record->id);
            $src = preg_replace('/_\d+x\d+/', "", $image->image);
            $src = "public://xfiles/" . $id . "/" . $src;
            $attr = array();
            if ( $image->caption ) {
              error_log("Setting caption to " . $image->caption);
              $attr['filename'] = trim($image->caption);
              $attr['field_caption'] = trim($image->caption);
            }
            if ( $image->attribution )
              $attr['field_attribution'] = trim($image->attribution);
            if ( $image->colour )
              $attr['field_colour'] = trim($image->colour);
              
            $file = _create_file_entity($src, $attr);
            $images[] = $file->uri;
          }
          if ( count($images) )
            $item['images'] = $images;
        }

        $result->items[] = $item;
      }
    }
    date_default_timezone_set($tz);
    return $result;
  }

  /**
   * Implements FeedsParser::getMappingSources().
   */
  public function getMappingSources() {
    return array(
      'title' => array(
        'name' => t('Title'),
        'description' => t('URL of the feed item.'),
      ),
      'subtitle' => array(
        'name' => t('Subtitle'),
        'description' => t('Last modified date as UNIX time GMT of the feed item.'),
      ),
      'abstract' => array(
        'name' => t('Abstract'),
        'description' => t('How frequently the page is likely to change.'),
      ),
      'description' => array(
        'name' => t('Description'),
        'description' => t('The priority of this URL relative to other URLs on the site.'),
      ),
      'subcategory' => array(
        'name' => t('Subcategory'),
      ),
      'is_recent' => array(
        'name' => t('Is recent'),
      ),
      'is_series' => array(
        'name' => t('Is series'),
      ),
      'collection_of' => array(
        'name' => t('Collection of'),
      ),
      'cost' => array(
        'name' => t('Cost'),
      ),
      'is_sold' => array(
        'name' => t('Is sold'),
      ),
      'thank_you' => array(
        'name' => t('Thank you'),
      ),
      'year' => array(
        'name' => t('Year'),
      ),
      'modified' => array(
        'name' => t('Date modified'),
      ),
      'materials' => array(
        'name' => t('Media'),
        'description' => t('Materials used to create the work.')
      ),
      'images' => array(
        'name' => t('Images'),
        'description' => t('An array of images.')
      ),
    ) + parent::getMappingSources();
  }
}

//  http://drupal.org/node/1438668
function _create_file_entity($src, $attrs=array(), $directory_path="feeds-importer") {
    // first check that the file exists
  if ( file_exists($src) ) {
        // create a file object for Drupal
    $file = (object) array(
      'uri' => $src,
      'filemime' => file_get_mimetype($src),
      'status' => 1,
      'display' => 'large',
    );    
  
    // now get Drupal to copy it
    //  we need to split the file from the filename
    $basename = basename($src);
    $drupalfile = file_copy($file, 'public://' . $directory_path . "/" . $basename);
        // we should have a file object with an id.  The id is all we need
    $fid = $drupalfile->fid;

    // load the entity for this file (note, returns an array, indexed on fid
    $file_entities = entity_load('file', array($fid));
//    if ( is_array($file_entities) )
//      error_log("array keys " . implode(', ', array_keys($file_entities)));

    $file_entity = $file_entities[$fid];
    foreach ($attrs as $key=>$value) {
      error_log("Setting $key to $value");
      $file_entity->$key = $value;
    }
    entity_save('file', $file_entity);
    error_log(var_export($file_entity, TRUE));

    //  reset the file name here

    return $file_entity;
  } else {
    error_log("$src does not exist.");
  }
}

function _decode_html($string) {
  return html_entity_decode((string) $string, ENT_COMPAT, 'UTF-8');
}