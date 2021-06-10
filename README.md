# KRSBIB SoundCloud Feed

Module provides custom panels pane which will display 3 latest podcasts from
KRSBIB's Soundcloud feed - https://soundcloud.com/krsbibpod.

The results are cached for one day, or 86400 seconds. To enforce reading the
feed before the cache expires - clear Drupal's cache.

## Installation
- Enable the **KRSBIB SoundCloud feed** module either via modules page, or via
  drush:
  `drush en krsbib_soundcloud_feed`.

## Usage
This module implements a panels pane which can be inserted on ctools pages.
Edit the respective page and place the **KRSBIB Soundcloud Feed** pane located
in the **Bibliofil** panes section.
