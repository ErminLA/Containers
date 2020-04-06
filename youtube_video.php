<?php
$ch = curl_init();
curl_setopt($ch, CURLOPT_URL, 'https://ermin3d.mylabserver.com:443/youtube_video');
curl_setopt($ch, CURLOPT_RETURNTRANSFER, true);
curl_setopt($ch, CURLOPT_FOLLOWLOCATION, true);
$data = curl_exec($ch);
curl_close($ch);
echo $data;
