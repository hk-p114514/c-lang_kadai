<?php

$max = 20;

$filenames = [];

for ($i=1; $i <= 20; $i++) {
    $filename =  "kadai$i.sql";
    array_push($filenames, $filename);
    echo $filename . PHP_EOL;
}

$titles = [];
for ($i=1; $i <= $max; $i++) {
    $title_number = sprintf('%02d', $i);
    echo $title_number . PHP_EOL;
    $title = "SQL01-$title_number";
    array_push($titles, $title);
}

mb_language("Japanese");
mb_internal_encoding("UTF-8");
$to = "ei2030@hamako-ths.ed.jp";
$headers = "From: ei2030@hamako-ths.ed.jp";

for ($i = 0; $i < 20; $i++) {
    $filename = $filenames[$i];
    $content = file_get_contents($filename);
    if ($content == false) {
        throw new RuntimeException('file not found');
    }

    echo $filename . "=========" . $titles[$i] . PHP_EOL;
    echo $content . PHP_EOL;


    if (
        mb_send_mail(
            $to,
            $title,
            $content,
            $headers
        )
    ) {
        echo "success $i $title" . PHP_EOL . "$content" . PHP_EOL;
    } else {
        echo "error $i $title" . PHP_EOL . "$content" . PHP_EOL;
    }
}
