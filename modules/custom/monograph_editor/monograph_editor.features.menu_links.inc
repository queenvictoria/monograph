<?php
/**
 * @file
 * monograph_editor.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function monograph_editor_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: shortcut-set-2:admin/content
  $menu_links['shortcut-set-2:admin/content'] = array(
    'menu_name' => 'shortcut-set-2',
    'link_path' => 'admin/content',
    'router_path' => 'admin/content',
    'link_title' => 'Find content',
    'options' => array(),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-47',
  );
  // Exported menu link: shortcut-set-2:admin/content/media
  $menu_links['shortcut-set-2:admin/content/media'] = array(
    'menu_name' => 'shortcut-set-2',
    'link_path' => 'admin/content/media',
    'router_path' => 'admin/content/media',
    'link_title' => 'Media library',
    'options' => array(),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-49',
  );
  // Exported menu link: shortcut-set-2:node/add
  $menu_links['shortcut-set-2:node/add'] = array(
    'menu_name' => 'shortcut-set-2',
    'link_path' => 'node/add',
    'router_path' => 'node/add',
    'link_title' => 'Add content',
    'options' => array(),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-48',
  );
  // Exported menu link: shortcut-set-2:node/add/project
  $menu_links['shortcut-set-2:node/add/project'] = array(
    'menu_name' => 'shortcut-set-2',
    'link_path' => 'node/add/project',
    'router_path' => 'node/add/project',
    'link_title' => 'Add project',
    'options' => array(),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-50',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Add content');
  t('Add project');
  t('Find content');
  t('Media library');


  return $menu_links;
}
