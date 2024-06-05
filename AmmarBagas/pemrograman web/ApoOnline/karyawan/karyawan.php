<?php session_start();?>
<!DOCTYPE html>
<html>

<head>
	<meta charset="utf-8">
	<meta name="viewport" content="width=device-width, initial-scale=1">
	<link rel="stylesheet" type="text/css" href="../assets/css/bootstrap.min.css">
	<link rel="icon" type="image/icon" href="../assets/image/logo2.png">
	
	<title>Welcome karyawan</title>
</head>

<body>

	<?php include "headerKaryawan.php" ?>


	<div class="container mt-5">
		<div class="row">
			<div class="col align-self-start">
				<div class="card">
					<div id="carouselExampleAutoplaying" class="carousel carousel-dark slide" data-bs-ride="carousel">
						<div class="carousel-inner">
							<div class="carousel-item active">
								<img src="../assets/image/produk-1.png" class="mx-auto d-block w-50" alt="...">
							</div>
							<div class="carousel-item">
								<img src="../assets/image/produk-2.png" class="mx-auto d-block w-50" alt="...">
							</div>
							<div class="carousel-item">
								<img src="../assets/image/produk-3.png" class="mx-auto d-block w-50" alt="...">
							</div>
							<div class="carousel-item">
								<img src="../assets/image/produk-4.png" class="mx-auto d-block w-50" alt="...">
							</div>
							<div class="carousel-item">
								<img src="../assets/image/produk-5.png" class="mx-auto d-block w-50" alt="...">
							</div>
						</div>
						<button class="carousel-control-prev" type="button" data-bs-target="#carouselExampleAutoplaying"
							data-bs-slide="prev">
							<span class="carousel-control-prev-icon" aria-hidden="true"></span>
							<span class="visually-hidden">Previous</span>
						</button>
						<button class="carousel-control-next" type="button" data-bs-target="#carouselExampleAutoplaying"
							data-bs-slide="next">
							<span class="carousel-control-next-icon" aria-hidden="true"></span>
							<span class="visually-hidden">Next</span>
						</button>
					</div>
					<div class="card-body">
						<h5 class="card-title">Product</h5>
						<p class="card-text">Silahkan klik tombol di bawah untuk melihat menambahkan dan menghapus
							product</p>
						<a href="#" class="btn btn-primary">Setting Product</a>
					</div>
				</div>
			</div>
			<div class="col align-self-end">
				<div class="card">
					<div id="carouselExampleInterval" class="carousel carousel-dark slide" data-bs-ride="carousel">
						<div class="carousel-inner">
							<div class="carousel-item active">
								<img src="../assets/image/produk-1.png" class="mx-auto d-block w-50" alt="...">
							</div>
							<div class="carousel-item">
								<img src="../assets/image/produk-2.png" class="mx-auto d-block w-50" alt="...">
							</div>
							<div class="carousel-item">
								<img src="../assets/image/produk-3.png" class="mx-auto d-block w-50" alt="...">
							</div>
							<div class="carousel-item">
								<img src="../assets/image/produk-4.png" class="mx-auto d-block w-50" alt="...">
							</div>
							<div class="carousel-item">
								<img src="../assets/image/produk-5.png" class="mx-auto d-block w-50" alt="...">
							</div>
						</div>
						<button class="carousel-control-prev" type="button" data-bs-target="#carouselExampleInterval"
							data-bs-slide="prev">
							<span class="carousel-control-prev-icon" aria-hidden="true"></span>
							<span class="visually-hidden">Previous</span>
						</button>
						<button class="carousel-control-next" type="button" data-bs-target="#carouselExampleInterval"
							data-bs-slide="next">
							<span class="carousel-control-next-icon" aria-hidden="true"></span>
							<span class="visually-hidden">Next</span>
						</button>
					</div>
					<div class="card-body">
						<h5 class="card-title">Pekerja</h5>
						<p class="card-text">Silahkan klik tombol di bawah untuk melihat menambahkan dan menghapus
							Pekerja</p>
						<a href="#" class="btn btn-primary">Setting Pekerja</a>
					</div>
				</div>
			</div>
		</div>

		<?php include "../home/footer.php" ?>

		<script type="text/javascript" src="../assets/js/bootstrap.bundle.min.js"></script>
</body>

</html>