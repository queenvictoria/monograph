<?php

/**
 * @file monograph_media/includes/themes/monograph_media.theme.inc
 *
 * Theme and preprocess functions for Media: YouTube.
 */

/**
 * Preprocess function for theme('monograph_media_video').
 */
function monograph_media_preprocess_monograph_media_video(&$variables) {
  // Build the URL for display.
//	print_r($variables);
  $uri = $variables['uri'];
  $wrapper = file_stream_wrapper_get_instance_by_uri($uri);

//	print_r(get_class_methods($wrapper));
//	print $wrapper->getUri();
/*	print "<br /> external ";
	print $wrapper->getExternalUrl();
	print "<br /> getMimeType ";
	print $wrapper->getMimeType();
	print "<br /> getTarget ";
	print $wrapper->getTarget();
	print "<br /> interpolateUrl ";
	print $wrapper->interpolateUrl ();
	print "<br /> parts ";
	*/
  $parts = $wrapper->get_parameters();
//	print_r($parts);
  $variables['video_id'] = check_plain($parts['v']);
	$external_link = $wrapper->getExternalUrl();
//	@todo - fix this up as it is using the youtube url format not the vimeo one . should be done
//	in media_vimeo and patched / submitted
	if ( $variables['scheme'] == 'vimeo' )
		$external_link = "http://vimeo.com/" . $variables['video_id'];

  $variables['width'] = isset($variables['width']) ? $variables['width'] : monograph_media_variable_get('width');
  $variables['height'] = isset($variables['height']) ? $variables['height'] : monograph_media_variable_get('height');
//  $variables['autoplay'] = isset($variables['autoplay']) ? $variables['autoplay'] : monograph_media_variable_get('autoplay');
//  $variables['fullscreen'] = isset($variables['fullscreen']) ? $variables['fullscreen'] : monograph_media_variable_get('fullscreen');
//  $variables['autoplay'] = $variables['autoplay'] ? 1 : 0;
//  $variables['fullscreen'] = $variables['fullscreen'] ? 'true' : 'false';

  $variables['wrapper_id'] = 'monograph_media_' . $variables['video_id'] . '_' . $variables['id'];
  // For users with JavaScript, these object and embed tags will be replaced
  // by an iframe, so that we can support users without Flash.
/*
  $variables['output'] = <<<OUTPUT
    <object width="{$variables['width']}" height="{$variables['height']}">
      <param name="movie" value="http://www.youtube.com/v/{$variables['video_id']}"></param>
      <param name="allowFullScreen" value="{$variables['fullscreen']}"></param>
      <param name="wmode" value="transparent" />
      <embed src="http://www.youtube.com/v/{$variables['video_id']}" type="application/x-shockwave-flash" width="{$variables['width']}" height="{$variables['height']}" allowfullscreen="{$variables['fullscreen']}"></embed>
    </object>
OUTPUT;
*/
// our variables include variables set up in media.formatters.

//	$preset_name = $variables['preset_name'];
//	print $preset_name;
//  $preset = styles_containers_available_styles('file', 'monograph_media', $preset_name);	
//  $preset = styles_containers_available_styles('file', 'monograph_media', $preset_name);
	$preset_name = "square_thumbnail";
	$thumbnail = file_create_url(image_style_path($preset_name, $variables['thumbnail']));
//	$output = "<img src='$thumbnail' />";
      $image_variables = array(
//        'path' => $wrapper->getOriginalThumbnailPath(),
        'alt' => $variables['media_caption'],
        'title' => $variables['media_caption'],
        'getsize' => TRUE,
      );
        $image_variables['path'] = $variables['thumbnail'];
       $image_variables['style_name'] = $preset_name;
	
//	create an image tag
	$output = theme('image_style', $image_variables);
//	print $output;
//	add an overlay
	$output .= "<div class='overlay'></div>";
//	link it to the source
	$options = array(
		'attributes' => array(
			'class' => array($variables['scheme'], 'monograph-video', $preset_name, implode('-', explode('/', $wrapper->getMimeType($uri)))),
			'title' => $variables['media_caption'],
		),
		'html' => TRUE,
	);
	$variables['output'] = l($output, $external_link, $options);

//      $image_variables = array(
//        'path' => $wrapper->getOriginalThumbnailPath(),
//        'alt' => $variables['alt'],
  //      'title' => $variables['title'],
    //    'getsize' => FALSE,
      //);
 //       $image_variables['path'] = $variables['lpath'];
   //     $image_variables['style_name'] = $preset['image_style'];
     //   $output = theme('image_style', $image_variables);


  // @todo Replace this inline JavaScript with at least calls to
  //   drupal_add_js()/drupal_get_js(), and ideally, with a behavior. Keep
  //   in mind that the solution needs to work when inside a colorbox or
  //   otherwise in an AJAX response, but that should now be possible in D7.
  $iframe_id = drupal_json_encode($variables['wrapper_id'] .'_iframe');
  $wrapper_id = drupal_json_encode($variables['wrapper_id']);
  $JSObject = 'Drupal.settings.monograph_media[' . $wrapper_id . ']';
  $variables['output'] .= <<<OUTPUT
    <script type="text/javascript">
      if (Drupal.settings && Drupal.monograph_media) {
        Drupal.settings.monograph_media = Drupal.settings.monograph_media || {};
        $JSObject = {};
        $JSObject.width = {$variables['width']};
        $JSObject.height = {$variables['height']};
        $JSObject.video_id = "{$variables['video_id']}";
        $JSObject.id = $iframe_id;
        Drupal.monograph_media.insertEmbed($wrapper_id);
      }
    </script>
OUTPUT;
/*
  drupal_add_js(drupal_get_path('module', 'monograph_media') . '/js/monograph_media.js');
  drupal_add_css(drupal_get_path('module', 'monograph_media') . '/css/monograph_media.css');
  drupal_add_js(drupal_get_path('module', 'monograph_media') . '/js/flash_detect_min.js');
*/
}

function theme_monograph_media_field_formatter_styles($variables) {
  $element = $variables['element'];
  $style = $variables['style'];
  $variables['file'] = $element['#item'];
  $variables['uri'] = $variables['file']['uri'];
  $variables['style_name'] = $style['name'];
  return theme('monograph_media_embed', $variables);
}

/**
 * Preview for Styles UI.
 */
function theme_monograph_media_preview_style($variables) {
  $variables['uri'] = monograph_media_variable_get('preview_uri');
  $variables['field_type'] = 'file';
  $variables['object'] = file_uri_to_object($variables['uri']);

  return theme('styles', $variables);
}

/**
 * NOTE: Deprecated with Styles version 2.
 */
function theme_monograph_media_styles($variables) {
  $style = $variables['style'];
  $variables['file'] = $variables['object'];
  $variables['uri'] = $variables['object']->uri;
  $variables['style_name'] = $style['name'];
  return theme('monograph_media_embed', $variables);
}

/**
 * @todo: get this working
 *
 * This code is for embedding videos in WYSIYWG areas, not currently working.
 * NOTE: Deprecated with Styles version 2.
 */
function theme_monograph_media_embed($variables) {
  $preset_name = $variables['preset_name'];
  $preset = styles_containers_available_styles('file', 'monograph_media', $preset_name);
  $output = '';
  if (!empty($preset)) {
    // Build the URL for display.
    $uri = $variables['uri'];
    $wrapper = file_stream_wrapper_get_instance_by_uri($uri);
    $parts = $wrapper->get_parameters();

    $fullscreen_value = $autoplay = 'false';
    $in_browser = $thumbnail = FALSE;

    foreach ($preset['effects'] as $effect) {
      switch ($effect['name']) {
        case 'autoplay':
          $autoplay = $effect['data']['autoplay'] ? 'true' : 'false';
          break;
        case 'resize':
          $width = $effect['data']['width'];
          $height = $effect['data']['height'];
          break;
        case 'fullscreen':
          $fullscreen_value = $effect['data']['fullscreen'] ? 'true' : 'false';
          break;
        case 'thumbnail':
          $thumbnail = $effect['data']['thumbnail'];
      }
    }
    if (isset($variables['object']->override)) {
      $override = $variables['object']->override;
      if (isset($override['width'])) {
        $width = $override['width'];
      }
      if (isset($override['height'])) {
        $height = $override['height'];
      }
      if (isset($override['wysiwyg'])) {
        $thumbnail = TRUE;
      }
      if (isset($override['browser']) && $override['browser']) {
        $in_browser = TRUE;
        $thumbnail = TRUE;
      }
    }
    $width = isset($width) ? $width : monograph_media_variable_get('width');
    $height = isset($height) ? $height : monograph_media_variable_get('height');
    $video_id = check_plain($parts['v']);
    if ($thumbnail) {
      // @todo Clean this up.
      $image_variables = array(
        'path' => $wrapper->getOriginalThumbnailPath(),
        'alt' => $variables['alt'],
        'title' => $variables['title'],
        'getsize' => FALSE,
      );
      if (isset($preset['image_style'])) {
        $image_variables['path'] = $wrapper->getLocalThumbnailPath();
        $image_variables['style_name'] = $preset['image_style'];
        $output = theme('image_style', $image_variables);
      }
      else {
        // We need to add this style attribute here so that it doesn't get lost
        // If you resize a video in a node, save it, edit it, but don't adjust
        // the sizing of the video while editing, the size will revert to the
        // default.  Adding the specific size here retains the original resizing
        $WYSIWYG = isset($variables['object']->override['style']) ? $variables['object']->override['style'] : '';
        $image_variables['attributes'] = array('width' => $width, 'height' => $height, 'style' => $WYSIWYG);
        $output = theme('image', $image_variables);
      }
      if ($in_browser) {
        // Add an overlay that says 'YouTube' to media library browser thumbnails.
        $output .= '<span />';
      }
    }
    else {
      $output = theme('monograph_media_video', array('uri' => $uri, 'width' => $width, 'height' => $height, 'autoplay' => ($autoplay == 'true' ? TRUE : NULL), 'fullscreen' => ($fullscreen_value == 'true' ? TRUE : NULL)));
    }
  }
  return $output;
}
