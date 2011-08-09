<?php

/**
 * @file media_monograph/includes/themes/media-monograph-thumbnail.tpl.php
 *
 * Template file for theme('media_monograph_thumbnail').
 *
 * Variables available:
 *  $uri - The uri to the monograph thumbnail, such as monograph://v/xsy7x8c9.
 *  $thumbnail_id - The unique identifier of the monograph thumbnail.
 *  $width - The width to render.
 *  $height - The height to render.
 *  $autoplay - If TRUE, then start the player automatically when displaying.
 *  $fullscreen - Whether to allow fullscreen playback.
 *
 * Note that we set the width & height of the outer wrapper manually so that
 * the JS will respect that when resizing later.
 */
?>
<div class="media-monograph-outer-wrapper" id="media-monograph-<?php print $id; ?>">
  <div class="media-monograph-preview-wrapper" id="<?php print $wrapper_id; ?>">
    <?php print $output; ?>
  </div>
</div>
