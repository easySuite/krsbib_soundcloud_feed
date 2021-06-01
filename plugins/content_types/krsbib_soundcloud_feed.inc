<?php

/**
 * @file
 * KRSBIB Soundcloud Feed custom panels pane.
 */

$plugin = [
  'single' => TRUE,
  'title' => t('KRSBIB Soundcloud Feed'),
  'description' => t('Display latest 3 podcasts from KRSBib soundcloud channel.'),
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
  $theme_variables = [
    'items' => array_map(function ($podcast) {
      return l($podcast['title'], $podcast['link'], [
        'absolute' => TRUE,
      ]);
    }, krsbib_soundcloud_feed_podcasts()),
    'title' => '',
    'type' => 'ul',
    'attributes' => [
      'class' => [
        'menu',
      ],
    ],
  ];

  $block = new stdClass();
  $block->content['#markup'] = theme('item_list', $theme_variables);

  return $block;
}
