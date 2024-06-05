<?php
	$host_name = "localhost";
	$db_user = "root";
	$db_pass = "";
	$db_name = "apotek_online";

	$connect = mysqli_connect($host_name, $db_user, $db_pass, $db_name);

	if (!$connect) {
		die("Database not connected!");
	}
?>