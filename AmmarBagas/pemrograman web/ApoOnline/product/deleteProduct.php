<?php
	include '../databases/db.php';

	if (isset($_GET['deleteid'])) {
		$id = $_GET['deleteid'];

		$sql = "DELETE FROM produk WHERE id = '$id'";
		$result = mysqli_query($connect, $sql);

		if ($result) {
			header("Location: ../admin/admin.php");
		} else {
			die(mysqli_error($connect));
		}
	}
?>