<?php

/**
 * @file
 */

/**
 * Implements hook_file_formatter_info().
 */
function monograph_media_file_formatter_info() {
  $formatters['monograph_media_video'] = array(
    'label' => t('Monograph Video'),
    'file types' => array('video'),
    'default settings' => array(
      'width' => 100,
      'height' => 100,
//      'autoplay' => monograph_media_variable_get('autoplay'),
    ),
    'view callback' => 'monograph_media_file_formatter_video_view',
    'settings callback' => 'monograph_media_file_formatter_video_settings',
  );
  $formatters['monograph_media_image'] = array(
    'label' => t('Monograph thumbnail'),
    'file types' => array('image'),
    'default settings' => array(
      'width' => 100,
      'height' => 100,
      'image_style' => '',
    ),
    'view callback' => 'monograph_media_file_formatter_image_view',
    'settings callback' => 'monograph_media_file_formatter_image_settings',
  );
  return $formatters;
}

/**
 * Implements hook_file_formatter_FORMATTER_view().
	- adds in all the required fields to the variables array that will be available for theming
	- doesn't make it as far as the theme
 */
function monograph_media_file_formatter_video_view($file, $display, $langcode) {
	$scheme = file_uri_scheme($file->uri);
  // WYSIWYG does not yet support video inside a running editor instance.
// schemes are the bit before the :// . eg : youtube:// vimeo:// etc.
//  if ($scheme == 'youtube' && empty($file->override['wysiwyg'])) {
//        '#path' => $wrapper->getOriginalThumbnailPath(),
  //      '#path' => $wrapper->getLocalThumbnailPath(),
	$wrapper = file_stream_wrapper_get_instance_by_uri($file->uri);
	$parts = $wrapper->get_parameters();
	$variables['video_id'] = check_plain($parts['v']);
	$external_link = $wrapper->getExternalUrl();
//	@todo - fix this up as it is using the youtube url format not the vimeo one . should be done
//	in media_vimeo and patched / submitted
	if ( $scheme == 'vimeo' )
		$external_link = "http://vimeo.com/" . $variables['video_id'];
	
	if (empty($file->override['wysiwyg'])) {
		$element = array(
			'#theme' => 'monograph_media_video',
			'#uri' => $file->uri,
			'#path' => $wrapper->getOriginalThumbnailPath(),
			'#thumbnail' => $wrapper->getLocalThumbnailPath(),
			'#external' => $external_link,
			'#scheme' => $scheme,
//			'#alt' => $file->alt,
//			'#title' => $file->title,
//			'#alt' => $alt,
//			'#title' => $title,			
		);
		foreach (array('width', 'height') as $setting) {
			$element['#' . $setting] = isset($file->override[$setting]) ? $file->override[$setting] : $display['settings'][$setting];
		}
//	put in all the fields we have on the file
		foreach ( $file as $key => $field ) {
			if ( strpos($key, 'field_') === 0 ) {
				$field_name = substr($key, 6);
				if ( array_key_exists('und', $field) ) {
					$element['#' . $field_name] = $field['und'][0]['safe_value'] ? $field['und'][0]['safe_value'] : '';
				} else {
					$element['#' . $field_name] = '';
				}
			}
		}
		
		return $element;
	}
}

/**
 * Implements hook_file_formatter_FORMATTER_settings().
	-	the settings fields for our formatter
 */
function monograph_media_file_formatter_video_settings($form, &$form_state, $settings) {
  $element = array();
  $element['width'] = array(
    '#title' => t('Width'),
    '#type' => 'textfield',
    '#default_value' => $settings['width'],
  );
  $element['height'] = array(
    '#title' => t('Height'),
    '#type' => 'textfield',
    '#default_value' => $settings['height'],
  );
/*
  $element['autoplay'] = array(
    '#title' => t('Autoplay'),
    '#type' => 'checkbox',
    '#default_value' => $settings['autoplay'],
  );
*/
  return $element;
}

/**
 * Implements hook_file_formatter_FORMATTER_view().
 */

function monograph_media_file_formatter_image_view($file, $display, $langcode) {
	$scheme = file_uri_scheme($file->uri);
  // WYSIWYG does not yet support video inside a running editor instance.
// schemes are the bit before the :// . eg : youtube:// vimeo:// etc.
//  if ($scheme == 'youtube' && empty($file->override['wysiwyg'])) {
//        '#path' => $wrapper->getOriginalThumbnailPath(),
  //      '#path' => $wrapper->getLocalThumbnailPath(),
	$wrapper = file_stream_wrapper_get_instance_by_uri($file->uri);
	
//	print $wrapper->getDirectoryPath() . "<br />";
//	print $wrapper->getExternalUrl() . "<br />";
//	print $wrapper->getMimeType() . "<br />";
//	print $wrapper->getUri() . "<br />";
	
	$uri = $wrapper->getUri();
	$preset_name = "large";
	$external_link = file_create_url(image_style_path($preset_name, $uri));
	
	if (empty($file->override['wysiwyg'])) {
		$element = array(
			'#theme' => 'monograph_media_video',
			'#uri' => $file->uri,
			'#path' => $uri,
			'#thumbnail' => $uri,
// @todo this should be our large size not the straigh url
			'#external' => $external_link,
			'#scheme' => $scheme,
//			'#alt' => $file->alt,
//			'#title' => $file->title,
//			'#alt' => $alt,
//			'#title' => $title,			
		);
		foreach (array('width', 'height') as $setting) {
			$element['#' . $setting] = isset($file->override[$setting]) ? $file->override[$setting] : $display['settings'][$setting];
		}
//	put in all the fields we have on the file
		foreach ( $file as $key => $field ) {
			if ( strpos($key, 'field_') === 0 ) {
				$field_name = substr($key, 6);
				if ( array_key_exists('und', $field) ) {
					$element['#' . $field_name] = $field['und'][0]['safe_value'] ? $field['und'][0]['safe_value'] : '';
				} else {
					$element['#' . $field_name] = '';
				}
			}
		}
		
		return $element;
	}
}


function OLD_monograph_media_file_formatter_image_view($file, $display, $langcode) {
  $scheme = file_uri_scheme($file->uri);
//  if ($scheme == 'youtube') {
    $wrapper = file_stream_wrapper_get_instance_by_uri($file->uri);
    $image_style = $display['settings']['image_style'];
    $valid_image_styles = image_style_options(FALSE);
    if (empty($image_style) || !isset($valid_image_styles[$image_style])) {
      $element = array(
        '#theme' => 'image',
        '#path' => $wrapper->getOriginalThumbnailPath(),
      );
    }
    else {
      $element = array(
        '#theme' => 'image_style',
        '#style_name' => $image_style,
        '#path' => $wrapper->getLocalThumbnailPath(),
      );
    }
    return $element;
//  }
}

/**
 * Implements hook_file_formatter_FORMATTER_settings().
 */
function monograph_media_file_formatter_image_settings($form, &$form_state, $settings) {
  $element = array();
  $element['image_style'] = array(
    '#title' => t('Image style'),
    '#type' => 'select',
    '#options' => image_style_options(FALSE),
    '#default_value' => $settings['image_style'],
    '#empty_option' => t('None (original image)'),
  );
  return $element;
}

/**
 * Implements hook_file_default_displays().
 */
function monograph_media_file_default_displays() {
  $default_displays = array();

  // Default settings for displaying as a video.
  $default_video_settings = array(
    'media_large' => array(
      'width' => 480,
      'height' => 360,
//      'autoplay' => FALSE,
    ),
    'media_original' => array(
      'width' => 640,
      'height' => 480,
 //     'autoplay' => monograph_media_variable_get('autoplay'),
    ),
  );
  foreach ($default_video_settings as $view_mode => $settings) {
    $display_name = 'video__' . $view_mode . '__monograph_media_video';
    $default_displays[$display_name] = (object) array(
      'api_version' => 1,
      'name' => $display_name,
      'status' => 1,
      'weight' => 1,
      'settings' => $settings,
    );
  }

  // Default settings for displaying a video preview image. We enable preview
  // images even for view modes that also play video, for use inside a running
  // WYSIWYG editor. The higher weight ensures that the video display is used
  // where possible.
  $default_image_styles = array(
    'media_preview' => 'square_thumbnail',
    'media_large' => 'large',
    'media_original' => ''
  );
  foreach ($default_image_styles as $view_mode => $image_style) {
    $display_name = 'video__' . $view_mode . '__monograph_media_image';
    $default_displays[$display_name] = (object) array(
      'api_version' => 1,
      'name' => $display_name,
      'status' => 1,
      'weight' => 2,
      'settings' => array('image_style' => $image_style),
    );
  }

  return $default_displays;
}
