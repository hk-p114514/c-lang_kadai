<?php

$max = 14;

$filenames = [];

$log = fopen("./mail_log.txt", "w");

for ($i=1; $i <= $max; $i++) {
    $filename =  "kadai$i.sql";
    array_push($filenames, $filename);
    $log1 = $filename . PHP_EOL;
    echo $log1;
    fwrite($log, $log1);
}

$titles = [];
for ($i=1; $i <= $max; $i++) {
    $title_number = sprintf('%02d', $i);
    echo $title_number . PHP_EOL;
    $title = "SQL02-$title_number";
    array_push($titles, $title);
}

mb_language("Japanese");
mb_internal_encoding("UTF-8");
$to = "ei2030@hamako-ths.ed.jp";
// $to = "takesi@hamako-ths.ed.jp";
$headers = "From: ei2030@hamako-ths.ed.jp";

for ($i = 0; $i < $max; $i++) {
    $filename = $filenames[$i];
    $content = file_get_contents($filename);
    if ($content == false) {
        throw new RuntimeException('file not found');
    }
    $title = $titles[$i];

    $log2 = $filename . "=========" . $title . PHP_EOL;
    $log3 = $content . PHP_EOL;
    echo $log2;
    echo $log3;
    fwrite($log, $log2);
    fwrite($log, $log3);


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
