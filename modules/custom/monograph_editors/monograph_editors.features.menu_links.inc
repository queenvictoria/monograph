<?php
/**
 * @file
 * monograph_editors.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function monograph_editors_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: shortcut-set-1:admin/config/development/performance
  $menu_links['shortcut-set-1:admin/config/development/performance'] = array(
    'menu_name' => 'shortcut-set-1',
    'link_path' => 'admin/config/development/performance',
    'router_path' => 'admin/config/development/performance',
    'link_title' => 'Performance',
    'options' => array(),
    'module' => 'menu',
    'hidden' => '1',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-43',
  );
  // Exported menu link: shortcut-set-1:admin/content
  $menu_links['shortcut-set-1:admin/content'] = array(
    'menu_name' => 'shortcut-set-1',
    'link_path' => 'admin/content',
    'router_path' => 'admin/content',
    'link_title' => 'Find content',
    'options' => array(),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-44',
  );
  // Exported menu link: shortcut-set-1:admin/content/file/thumbnails
  $menu_links['shortcut-set-1:admin/content/file/thumbnails'] = array(
    'menu_name' => 'shortcut-set-1',
    'link_path' => 'admin/content/file/thumbnails',
    'router_path' => 'admin/content/file/thumbnails',
    'link_title' => 'Media library',
    'options' => array(),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-50',
  );
  // Exported menu link: shortcut-set-1:admin/structure/block
  $menu_links['shortcut-set-1:admin/structure/block'] = array(
    'menu_name' => 'shortcut-set-1',
    'link_path' => 'admin/structure/block',
    'router_path' => 'admin/structure/block',
    'link_title' => 'Edit blocks',
    'options' => array(),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-46',
  );
  // Exported menu link: shortcut-set-1:admin/structure/menu/manage/main-menu
  $menu_links['shortcut-set-1:admin/structure/menu/manage/main-menu'] = array(
    'menu_name' => 'shortcut-set-1',
    'link_path' => 'admin/structure/menu/manage/main-menu',
    'router_path' => 'admin/structure/menu/manage/%',
    'link_title' => 'Edit menu',
    'options' => array(),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-47',
  );
  // Exported menu link: shortcut-set-1:admin/structure/taxonomy/category
  $menu_links['shortcut-set-1:admin/structure/taxonomy/category'] = array(
    'menu_name' => 'shortcut-set-1',
    'link_path' => 'admin/structure/taxonomy/category',
    'router_path' => 'admin/structure/taxonomy/%',
    'link_title' => 'Edit project terms (categories)',
    'options' => array(),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-48',
  );
  // Exported menu link: shortcut-set-1:node/add
  $menu_links['shortcut-set-1:node/add'] = array(
    'menu_name' => 'shortcut-set-1',
    'link_path' => 'node/add',
    'router_path' => 'node/add',
    'link_title' => 'Add content',
    'options' => array(),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-45',
  );
  // Exported menu link: shortcut-set-1:node/add/project
  $menu_links['shortcut-set-1:node/add/project'] = array(
    'menu_name' => 'shortcut-set-1',
    'link_path' => 'node/add/project',
    'router_path' => 'node/add/project',
    'link_title' => 'Add project',
    'options' => array(),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-49',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Add content');
  t('Add project');
  t('Edit blocks');
  t('Edit menu');
  t('Edit project terms (categories)');
  t('Find content');
  t('Media library');
  t('Performance');


  return $menu_links;
}
