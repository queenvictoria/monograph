<?php
/**
 * @file
 * monograph_projects.features.inc
 */

/**
 * Implementation of hook_node_info().
 */
function monograph_projects_node_info() {
  $items = array(
    'project' => array(
      'name' => t('Project'),
      'base' => 'node_content',
      'description' => t('This is the default type for all records about works of art or text.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
