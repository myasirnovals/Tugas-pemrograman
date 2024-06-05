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
					<div class="row">
						<div class="col-sm-4">
							<div class="card mb-3" style="max-width: 540px;">
							  <div class="row g-0">
							    <div class="col-md-4">
							      <img src="../assets/imageItem/money.png" class="img-fluid rounded-start" alt="...">
							    </div>
							    <div class="col-md-8" style="padding-left: 25px;">
							      <div class="card-body">
							        <h5 class="card-title">Jumlah Uang</h5>
							        <p class="card-text">Rp.</p>
							      </div>
							    </div>
							  </div>
							</div>
						</div>
						<div class="col-sm-4">
							<div class="card mb-3" style="max-width: 540px;">
							  <div class="row g-0">
							    <div class="col-md-4">
							      <img src="../assets/imageItem/box.png" class="img-fluid rounded-start" alt="...">
							    </div>
							    <div class="col-md-8">
							      <div class="card-body" style="padding-left: 25px;">
							        <h5 class="card-title">Jumlah Produk</h5>
							        <p class="card-text">-</p>
							      </div>
							    </div>
							  </div>
							</div>
						</div>
						<div class="col-sm-4">
							<div class="card mb-3" style="max-width: 540px;">
							  <div class="row g-0">
							    <div class="col-md-4">
							      <img src="../assets/imageItem/chart.png" class="img-fluid rounded-start" alt="...">
							    </div>
							    <div class="col-md-8">
							      <div class="card-body" style="padding-left: 25px;">
							        <h5 class="card-title">Jumlah Pesanan</h5>
							        <p class="card-text">-</p>
							      </div>
							    </div>
							  </div>
							</div>
						</div>
					</div>
				</div>
				<div class="container mb-5">
					<div class="mt-3 mb-3">
						<div class="form-btn d-flex justify-content-between">
							<span style="text-shadow: 2px 3px 4px; font-size: 27px;">
								Product
							</span>
							<a href="../product/addProduct.php" class="btn btn-secondary">
								<span>Tambah produk</span>
								<i class="fa-solid fa-plus"></i>
							</a>
						</div>
					</div>
					<table class="table border">
					  <thead class="table-dark">
					    <tr>
					      <th scope="col">No.</th>
					      <th scope="col">Nama</th>
					      <th scope="col">Keterangan</th>
					      <th scope="col">Harga</th>
					      <th scope="col">Gambar</th>
					      <th scope="col">Tanggal Kedaluwarsa</th>
					      <th scope="col">Aksi</th>
					    </tr>
					  </thead>
					  <tbody>
					  	<?php
					  		include "../databases/db.php";

					  		$sql = "SELECT * FROM produk";
					  		$result = mysqli_query($connect, $sql);
					  		$i=1;

					  		if ($result) {
					  			while ($row = mysqli_fetch_assoc($result)) {
					  				$id = $row['id'];
					  				$nama_produk = $row['nama_produk'];
					  				$keterangan_produk = $row['keterangan_produk'];
					  				$harga = number_format($row["harga"], 0, ",", ".");
					  				$gambar_produk = $row['gambar_produk'];
					  				$tanggal_exp = $row['tanggal_exp'];
					  				

					  				echo "
									    <tr>
									      <th scope='row' class='text-center'>".$i++."</th>
									      <td>".$nama_produk."</td>
									      <td>".$keterangan_produk."</td>
									      <td>Rp.".$harga."</td>
									      <td><img src='../assets/imageProduct/".$gambar_produk."' width='100px'></td>
									      <td>".$tanggal_exp."</td>
									      <td>
									      	<a href='../product/editProduct.php?updateid=".$id."' class='btn btn-warning'>Edit</a>
									      	<a href='../product/deleteProduct.php?deleteid=".$id."' class='btn btn-danger'>Hapus</a>
									      </td>
									    </tr>
					  				";
					  			}
					  		}
					  	?>
					  </tbody>
					</table>
				</div>
			</div>
		</div>
	</div>


	<script type="text/javascript" src="../assets/js/bootstrap.bundle.min.js"></script>
</body>
</html>