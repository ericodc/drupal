<?php
/**
 * @file
 * song_example.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function song_example_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "feeds" && $api == "feeds_importer_default") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function song_example_node_info() {
  $items = array(
    'songs' => array(
      'name' => t('Songs'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
