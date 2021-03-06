<?php

/**
 * @file
 * Administrative page and form callbacks for the Advanced Queue module.
 */


/**
 * Form callback: builds the Advanced Queue settings form.
 */
function advancedqueue_settings_form($form, &$form_state) {
  $form['advancedqueue_threshold'] = array(
    '#type' => 'select',
    '#title' => t('Number of completed items to keep in the database'),
    '#default_value' => variable_get('advancedqueue_threshold', 0),
    '#options' => array(0 => t('All')) + drupal_map_assoc(array(100, 1000, 10000, 100000, 1000000)),
  );

  $form['advancedqueue_release_timeout'] = array(
    '#type' => 'select',
    '#title' => t('Time to wait before releasing an expired item'),
    '#default_value' => variable_get('advancedqueue_release_timeout', 0),
    '#options' => array(0 => t('Never')) + drupal_map_assoc(array(3600, 10800, 21600, 43200, 86400, 604800), 'format_interval'),
  );

  return system_settings_form($form);
}
