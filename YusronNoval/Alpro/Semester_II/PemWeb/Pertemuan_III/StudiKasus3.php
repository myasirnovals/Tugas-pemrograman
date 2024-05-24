<!DOCTYPE html>
<html>
<head>
	<meta charset="utf-8">
	<meta name="viewport" content="width=device-width, initial-scale=1">
	<link rel="stylesheet" href="assets/css/bootstrap.min.css">
	<link rel="stylesheet" type="text/css" href="assets/style.css">
	<title>Studi Kasus 3</title>
</head>
<body>
	<div class="container">
		<?php 
			if (isset($_POST["submit"])) {
				$nama = $_POST["nama"];
				$perusahaan = $_POST["perusahaan"];
				$email = $_POST["email"];
				$telepon = $_POST["telepon"];
				$catatan = $_POST["catatan"];

				$errors = array();

				if (empty($nama)) {
					array_push($errors, "Nama tidak boleh kosong");
				} else {
					echo "<div class='alert alert-success'>Nama sudah diisi</div>";
				}

				if (empty($perusahaan)) {
					array_push($errors, "Perusahaan tidak boleh kosong");
				} else {
					echo "<div class='alert alert-success'>Perusahaan sudah diisi</div>";
				}

				if (!filter_var($email, FILTER_VALIDATE_EMAIL)) {
					array_push($errors, "Email tidak boleh valid atau tidak boleh kosong");
				} else {
					echo "<div class='alert alert-success'>Email sudah diisi</div>";
				}

				if (empty($telepon)) {
					array_push($errors, "Nomor telepon tidak boleh kosong");
				} else {
					echo "<div class='alert alert-success'>Nomor telepon sudah diisi</div>";
				}

				if (empty($catatan)) {
					array_push($errors, "Catatan tidak boleh kosong");
				} else {
					echo "<div class='alert alert-success'>Catatan sudah diisi</div>";
				}

				if (count($errors)>0) {
					foreach ($errors as $error) {
						echo "<div class='alert alert-danger'>$error</div>";
					}
				} else {
					echo "<div class='alert alert-success'>Semua elemen input berhasil diisi.</div>";
				}
			}
		?>
		<form action="StudiKasus3.php" method="post">
			<table>
				<tr>
					<td><label>Nama</label></td>
					<td>:</td>
					<td>
						<input type="text" class="form-control" name="nama">
					</td>
				</tr>
				<tr>
					<td><label>Perusahaan</label></td>
					<td>:</td>
					<td>
						<input type="text" class="form-control" name="perusahaan">
					</td>
				</tr>
				<tr>
					<td><label>Email</label></td>
					<td>:</td>
					<td>
						<input type="email" class="form-control" name="email">
					</td>
				</tr>
				<tr>
					<td><label>Telepon</label></td>
					<td>:</td>
					<td>
						<input type="text" class="form-control" name="telepon" maxlength="12">
					</td>
				</tr>
				<tr>
					<td><label>Catatan</label></td>
					<td>:</td>
					<td>
						<textarea name="catatan" class="form-control"></textarea>
					</td>
				</tr>
				<tr>
					<td colspan="3" align="center" style="padding-top: 20px;">	
						<input type="submit" name="submit" value="Submit">
					</td>
				</tr>
			</table>
		</form>
	</div>

	<script src="https://cdn.jsdelivr.net/npm/@popperjs/core@2.11.8/dist/umd/popper.min.js" integrity="sha384-I7E8VVD/ismYTF4hNIPjVp/Zjvgyol6VFvRkX/vR+Vc4jQkC+hVqc2pM8ODewa9r" crossorigin="anonymous"></script>
	<script src="https://cdn.jsdelivr.net/npm/bootstrap@5.3.3/dist/js/bootstrap.min.js" integrity="sha384-0pUGZvbkm6XF6gxjEnlmuGrJXVbNuzT9qBBavbLwCsOGabYfZo0T0to5eqruptLy" crossorigin="anonymous"></script>
</body>
</html>