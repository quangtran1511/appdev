<?php
//$data = $_POST['data'];
//$ID = $_POST['ID'];
//$name = $_POST['name'];
//$today = date("Y-m-d H:i:s");	//timestamp of this reception
//$record = $today . ", " . $ID . ", " . $name . "\n";	//a piece of record
//$row = $_POST['row'];
//$col = $_POST['col'];
//$addr = $_SERVER['REMOTE_ADDR'];
$peaks = $_POST['Peaks'];
$max = $_POST['MaxdB'];
$today = date("Y-m-d H:i:s");	//timestamp of this reception
$record = $today . ", " . "Total peaks:" . $peaks . "& Maximum decibel: " . $max . "\n";

$file = "sound.log";	//specify the log file
if(file_exists($file))	//if the file already
	$fp = fopen($file, "a");
else
	$fp = fopen($file, "w");	//else open the file in writing mode
fwrite($fp, $record);
fclose(fp);
echo "From e1900293\n";
?>
