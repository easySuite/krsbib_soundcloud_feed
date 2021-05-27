<?php

/**
 * @file
 * KRSBIB Soundcloud feed template.
 *
 * @var array $content
 */
?>
<table>
    <tbody>
    <?php foreach ($content as $key => $item) : ?>
        <tr class="<?php print ($key % 2 === 0) ? 'odd' : 'even'; ?>">
            <td>
              <?php print l($item['title'], $item['link'], [
                'external' => TRUE,
                'attributes' => [
                  'target' => '_blank',
                ],
              ]); ?>
            </td>
        </tr>
    <?php endforeach; ?>
    </tbody>
</table>
