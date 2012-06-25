<?php
/**
 * @file
 * monograph_editors.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function monograph_editors_user_default_roles() {
  $roles = array();

  // Exported role: editor.
  $roles['editor'] = array(
    'name' => 'editor',
    'weight' => '3',
  );

  return $roles;
}
