<?php
/**
 * @file
 * song_example.feeds_importer_default.inc
 */

/**
 * Implements hook_feeds_importer_default().
 */
function song_example_feeds_importer_default() {
  $export = array();

  $feeds_importer = new stdClass;
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'album_importer';
  $feeds_importer->config = array(
    'name' => 'Album Importer',
    'description' => 'Import album data from csv files',
    'fetcher' => array(
      'plugin_key' => 'FeedsFileFetcher',
      'config' => array(
        'allowed_extensions' => 'txt csv tsv xml opml',
        'direct' => FALSE,
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsCSVParser',
      'config' => array(
        'delimiter' => ',',
        'no_headers' => 0,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsNodeProcessor',
      'config' => array(
        'content_type' => 'songs',
        'expire' => '-1',
        'author' => 0,
        'mappings' => array(
          0 => array(
            'source' => 'Title',
            'target' => 'title',
            'unique' => FALSE,
          ),
          1 => array(
            'source' => 'Artist',
            'target' => 'field_artist',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'Album',
            'target' => 'field_album',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'Time',
            'target' => 'field_time',
            'unique' => FALSE,
          ),
          4 => array(
            'source' => 'GUID',
            'target' => 'guid',
            'unique' => 1,
          ),
        ),
        'update_existing' => '0',
        'input_format' => 'plain_text',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => 1800,
    'expire_period' => 3600,
    'import_on_create' => TRUE,
    'process_in_background' => FALSE,
  );
  $export['album_importer'] = $feeds_importer;

  return $export;
}
