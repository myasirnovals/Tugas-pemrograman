<!DOCTYPE html>
<html>
<head>
	<meta charset="utf-8">
	<meta name="viewport" content="width=device-width, initial-scale=1">
	<link rel="stylesheet" type="text/css" href="assets/css/bootstrap.min.css">
	<link rel="icon" type="image/icon" href="assets/image/logo2.png">
	<title>Apotek Online</title>
</head>
<body>
	<?php
		include "home/header.php";
	?>

	<div class="container m-5">
		<div class="row">
			<div class="col mb-5">
				<h1 class="text-center Shadows" style="text-shadow: 2px 3px 4px;">Welcome to Apotek Online Store</h1>
			</div>
		</div>

		<?php include "home/mainContent.php"; ?>
	</div>
	<br><br>
	<?php
		include "home/footer.php";
	?>
	<script type="text/javascript" src="assets/js/bootstrap.bundle.min.js"></script>
</body>
</html>