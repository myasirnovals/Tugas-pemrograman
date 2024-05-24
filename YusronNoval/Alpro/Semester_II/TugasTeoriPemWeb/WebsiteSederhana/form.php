<!DOCTYPE html>
<html>
<head>
	<meta charset="utf-8">
	<meta name="viewport" content="width=device-width, initial-scale=1">
    <link rel="stylesheet" href="assets/css/bootstrap.min.css" />
    <link rel="stylesheet" href="assets/style.css" />
	<title></title>
</head>
<body>
	<?php include "header.php" ?>

	<form action="" method="post">
		<?php
			include "DB/db.php";

			if (isset($_POST["submit"])) {
				$nama = $_POST["nama"];
				$nim = $_POST["nim"];
				$kelas = $_POST["kelas"];
				$angkatan = $_POST["angkatan"];

				$sql = "INSERT INTO user(nama, nim, kelas, angkatan) VALUES ('$nama','$nim','$kelas','$angkatan')";
				$result = mysqli_query($connect,$sql);
				if ($result) {
					echo "<div alert('Data anda sudah berhasil terkirim')></div>";
					header("Location: index.php");
				} else {
					die(mysqli_error($connect));
				}
			}
		?>

		<div class="body">
	    	<div class="container-fluid">
	        	<div class="row">
					<div class="col-sm-12" style="padding-left: 200px; padding-right: 200px;">
		            	<div class="card p-4">
		              		<div class="card-body">
				                <h5 class="card-tittle text-center">Masukan Data Diri Mahasiswa</h5>
				                <hr />
				                <table>
				                	<tr>
				                		<td class="table-left">
				                			<label for="nama" class="card-text Cards-point">Nama</label>
				                		</td>
				                		<td class="table-mid">:</td>
				                		<td style="width: 500px;" class="table-right">
				                			<input type="text" name="nama" id="nama" class="form-control" placeholder="Masukan nama anda..." required>
				                		</td>
				                	</tr>
				                	<tr>
				                		<td class="table-left">
				                			<label for="nim" class="card-text Cards-point">NIM</label>
				                		</td>
				                		<td class="table-mid">:</td>
				                		<td class="table-right">
				                			<input type="text" name="nim" id="nim" class="form-control" maxlength="12" placeholder="Masukan NIM anda..." required>
				                		</td>
				                	</tr>
				                	<tr>
				                		<td class="table-left">
				                			<label for="kelas" class="card-text Cards-point">Kelas</label>
				                		</td>
				                		<td class="table-mid">:</td>
				                		<td class="table-right">
				                			<select class="form-select form-control" name="kelas" id="kelas">
				                				<option selected>Silahkan pilih kelas</option>
				                				<option value="A">A</option>
				                				<option value="B">B</option>
				                				<option value="C">C</option>
				                				<option value="D">D</option>
				                				<option value="E">E</option>
				                			</select>
				                		</td>
				                	</tr>
				                	<tr>
				                		<td class="table-left">
				                			<label for="angkatan" class="card-text Cards-point">Angkatan</label>
				                		</td>
				                		<td class="table-mid">:</td>
				                		<td class="table-right">
				                			<input type="text" name="angkatan" id="angkatan" class="form-control" placeholder="Masukan angkatan ke..." required>
				                		</td>
				                	</tr>
				                </table>
				                <div class="text-center" style="padding-top: 30px;">
	                				<input type="submit" name="submit" value="Submit" class="btn btn-success">
	                				<a href="index.php" class="btn btn-danger">Cancel</a>
	                			</div>
		              		</div>
		            	</div>
		          	</div>
		        </div>
		    </div>
		</div>
	</form>

	<?php include "footer.php" ?>


	<script src="assets/js/bootstrap.bundle.min.js"></script>
    <script src="https://cdn.jsdelivr.net/npm/@popperjs/core@2.11.8/dist/umd/popper.min.js" integrity="sha384-I7E8VVD/ismYTF4hNIPjVp/Zjvgyol6VFvRkX/vR+Vc4jQkC+hVqc2pM8ODewa9r" crossorigin="anonymous"></script>
	<script src="https://cdn.jsdelivr.net/npm/bootstrap@5.3.3/dist/js/bootstrap.min.js" integrity="sha384-0pUGZvbkm6XF6gxjEnlmuGrJXVbNuzT9qBBavbLwCsOGabYfZo0T0to5eqruptLy" crossorigin="anonymous"></script>
</body>
</html>