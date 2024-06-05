<?php
	session_start();
	if (!isset($_SESSION["user"])) {
		header("Location: ../form/login.php");
	}
?>

<!DOCTYPE html>
<html>
<head>
	<link rel="stylesheet" type="text/css" href="../assets/css/bootstrap.min.css">
	<link rel="icon" type="image/icon" href="../assets/image/logo2.png">
	<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/6.5.2/css/all.min.css" integrity="sha512-SnH5WK+bZxgPHs44uWIX+LLJAJ9/2PkPKZ5QiAj6Ta86w+fsb2TkcmfRyVX3pBnMFcV7oQPJkl9QevSCWr3W6A==" crossorigin="anonymous" referrerpolicy="no-referrer" />
	<title>Apotek Online</title>
</head>
<body>
	<div class="container-fluid">
		<div class="row">
			<div class="col-2 bg-dark bg-gradient rounded-end">
				<div class="container pt-4 mb-5">
					<img src="../assets/imageUser/admin.jpg" class="bg-light rounded w-50 d-block mx-auto" title="Admin" style="cursor: pointer;">
				</div>
				<div class="form-btn mt-3 text-center">
					<a href="../admin/admin.php" class="btn btn-light">
						<i class="fa-solid fa-house"></i>
						<span>Home</span>
					</a>
				</div>
				<div class="form-btn mt-3 text-center">
					<a href="#" class="btn btn-light">
						<i class="fa-solid fa-chart-column"></i>
						<span>Statistic</span>
					</a>
				</div>
				<div class="form-btn mt-3 text-center">
					<a href="#" class="btn btn-light">
						<i class="fa-solid fa-box"></i>
						<span>Product</span>
					</a>
				</div>
				<div class="form-btn mt-3 text-center">
					<a href="#" class="btn btn-light">
						<i class="fa-solid fa-user-tie"></i>
						<span>Workers</span>
					</a>
				</div>
				<div class="form-btn mt-3 text-center">
					<a href="../form/logout.php" class="btn btn-light">
						<i class="fa-solid fa-arrow-right-from-bracket"></i>
						<span>Log out</span>
					</a>
				</div>
			</div>
			<div class="col-10">
				<div class="container-fluid">
					<div class="row">
						<div class="col m-3 mb-5">
							<h1 class="text-center Shadows" style="text-shadow: 2px 3px 4px;">
								Apotek Online Store
							</h1>
						</div>
					</div>
					<div class="container mb-5">
						<?php
							include "../databases/db.php";

							if (isset($_POST['submit'])) {
								$nama_produk = $_POST["nama_produk"];
								$keterangan_produk = $_POST["keterangan_produk"];
								$harga = $_POST["harga"];
								$foto_name = $_FILES["gambar_produk"]["name"];
								$foto_size = $_FILES["gambar_produk"]["size"];
								$tmp_name = $_FILES["gambar_produk"]["tmp_name"];
								$tanggal_exp = $_POST["tanggal_exp"];

								$valid_foto_extension = ["jpg","png","jpeg"];
								$foto_extension = explode(".", $foto_name);
								$foto_extension = strtolower(end($foto_extension));

								$errors = array();

								if (empty($nama_produk) AND empty($harga) AND empty($keterangan_produk) AND empty($tanggal_exp) AND empty($foto_extension)) {
									array_push($errors, "Semua field tidak boleh kosong");
								}

								else if (empty($nama_produk)) {
									array_push($errors, "Produk tidak boleh kosong");
								}

								else if (empty($keterangan_produk)) {
									array_push($errors, "Keterangan produk tidak boleh kosong");
								}

								else if (empty($harga)) {
									array_push($errors, "Harga produk tidak boleh kosong");
								}

								else if (empty($tanggal_exp)) {
									array_push($errors, "Tanggal kedaluwarsa tidak boleh kosong");
								}

								else if (!in_array($foto_extension, $valid_foto_extension)) {
									array_push($errors,"Ekstensi gambar tidak valid");
								} 

								else if($foto_size > 1000000){
									array_push($errors,"Ukuran gambar terlalu besar");
								
								} 

								if (count($errors)>0) {
									foreach ($errors as $error) {
										echo "<div class='alert alert-danger'>$error</div>";
									}
								} else {
									$new_foto_name = uniqid();
									$new_foto_name .= ".".$foto_extension;

									move_uploaded_file($tmp_name, "../assets/imageProduct/".$new_foto_name);
									$sql = "INSERT INTO produk (nama_produk, harga, keterangan_produk, gambar_produk, tanggal_exp) VALUES ('$nama_produk', '$harga', '$keterangan_produk', '$new_foto_name', '$tanggal_exp')";
									$result = mysqli_query($connect, $sql);
									if ($result) {
										echo "<div class='alert alert-success'>Produk sudah berhasil ditambahkan</div>";
									} else {
										die(mysqli_error($connect));
									}
								}
							}
						?>
						<div class="card">
						  <div class="card-header text-center">
						    Add product
						  </div>
						  <div class="card-body">
							<form action="addProduct.php" method="post" enctype="multipart/form-data">
								<div class="mb-3">
							    	<label for="exampleInputEmail1" class="form-label">Nama produk</label>
							    	<input type="text" name="nama_produk" class="form-control" id="exampleInputEmail1" aria-describedby="emailHelp">
							  	</div>
							  	<div class="mb-3">
							    	<label for="exampleInputPassword1" class="form-label">Keterangan</label>
							    	<input type="text" name="keterangan_produk" class="form-control" id="exampleInputPassword1">
							  	</div>
							  	<div class="mb-3">
							    	<label for="exampleInputHarga1" class="form-label">Harga</label>
							    	<input type="text" name="harga" class="form-control" id="exampleInputHarga1">
							  	</div>
							  	<div class="input-group mb-3">
							  		<div class="input-group">
							  			<label for="inputGroupFile02" class="form-label">Gambar produk</label>
							  		</div>
								  	<input type="file" name="gambar_produk" class="form-control" id="inputGroupFile02">
								  	<label class="input-group-text" for="inputGroupFile02">Upload</label>
								</div>
								<div class="mb-3">
							    	<label for="exampleInputDate1" class="form-label">Tanggal expired</label>
							    	<input type="date" name="tanggal_exp" class="form-control" id="exampleInputDate1">
							  	</div>
							  	<div class="form-btn pt-3">
								  	<input type="submit" name="submit" class="btn btn-success" value="Submit">
								  	<a href="../admin/admin.php" class="btn btn-danger">Cancel</a>
							  	</div>
							</form>
						  </div>
						</div>
					</div>
				</div>
			</div>
		</div>
	</div>


	<script type="text/javascript" src="../assets/js/bootstrap.bundle.min.js"></script>
</body>
</html>