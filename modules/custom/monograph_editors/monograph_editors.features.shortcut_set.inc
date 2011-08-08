<?php
/**
 * @file
 * monograph_editors.features.shortcut_set.inc
 */

/**
 * Implementation of hook_shortcut_default_shortcut_set().
 */
function monograph_editors_shortcut_default_shortcut_set() {
  $shortcut_sets = array();
  $shortcut_sets['shortcut-set-1'] = array(
    'set_name' => 'shortcut-set-1',
    'title' => 'Default',
  );
  return $shortcut_sets;
}
