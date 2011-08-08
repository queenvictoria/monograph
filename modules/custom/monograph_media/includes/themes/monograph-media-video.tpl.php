<?php

/**
 * @file media_monograph/includes/themes/media-monograph-video.tpl.php
 *
 * Template file for theme('media_monograph_video').
 *
 * Variables available:
 *  $uri - The uri to the monograph video, such as monograph://v/xsy7x8c9.
 *  $video_id - The unique identifier of the monograph video.
 *  $width - The width to render.
 *  $height - The height to render.
 *  $autoplay - If TRUE, then start the player automatically when displaying.
 *  $fullscreen - Whether to allow fullscreen playback.
 *
 * Note that we set the width & height of the outer wrapper manually so that
 * the JS will respect that when resizing later.
 */
?>
<div class="media-monograph-outer-wrapper" id="media-monograph-<?php print $id; ?>" style="width: <?php print $width; ?>px; height: <?php print $height; ?>px;">
  <div class="media-monograph-preview-wrapper" id="<?php print $wrapper_id; ?>">
    <?php print $output; ?>
  </div>
</div>
