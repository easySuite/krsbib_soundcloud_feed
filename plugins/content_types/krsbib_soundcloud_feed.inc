<?php

/**
 * @file
 * KRSBIB Soundcloud Feed custom panels pane.
 */

$plugin = [
  'single' => TRUE,
  'title' => t('KRSBIB Soundcloud Feed'),
  'description' => t('Display last 3 podcasts from krsbib soundcloud account.'),
  'category' => t('Bibliofil'),
  'render callback' => 'krsbib_soundcloud_feed_render',
  'edit form' => 'krsbib_soundcloud_feed_edit_form',
];

/**
 * Pane settings form.
 */
function krsbib_soundcloud_feed_edit_form($form, &$form_state) {
  return $form;
}

/**
 * KRSBIB soundcloud feed rendering callback.
 */
function krsbib_soundcloud_feed_render($subtype, $conf, $args, $context) {
  $podcasts = [];

  $fetched_data = simplexml_load_file('https://feeds.soundcloud.com/users/soundcloud:users:253143255/sounds.rss');

  foreach ($fetched_data->channel->item as $item) {
    $podcasts[] = [
      'title' => (string) $item->title,
      'link' => (string) $item->link,
    ];
  }

  $podcasts = array_slice($podcasts, 0, 3);

  $block = new stdClass();
  $block->content['#markup'] = theme('krsbib_soundcloud_feed', ['content' => $podcasts]);
  return $block;
}
