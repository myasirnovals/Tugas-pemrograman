<?php
	include 'DB/db.php';

	if (isset($_GET["id"])) {
		$id = $_GET["id"];
	}

	$sql = "SELECT * FROM user";
	$result = mysqli_query($connect, $sql);
?>

<!DOCTYPE html>
<html lang="en">
<head>
	<meta charset="utf-8" />
    <meta name="viewport" content="width=device-width, initial-scale=1" />
    <link rel="stylesheet" href="assets/css/bootstrap.min.css" />
    <link rel="stylesheet" href="assets/style.css" />
    <title>Web Sederhana</title>
</head>
<body>
	<?php include "header.php" ?>

    <div class="body">
    	<div class="container-fluid">
        	<div class="row">
          		<div class="col-sm-4">
            		<div class="card p-4">
              			<div class="card-body">
                			<h5 class="card-tittle">Data Mahasiswa</h5>
                			<hr />
                			<a href="form.php" class="btn btn-success">tambah +</a>
            				<button class="btn btn-info dropdown-toggle" type="button" data-bs-toggle="dropdown" >
						    	Silahkan pilih MHS
						  	</button>
						  	<ul class="dropdown-menu">
						  		<li><a class="dropdown-item" href="index.php">Pilih...</a></li>
						    	<?php
						    		$i = 1;

						    		if ($result) {
						    			while($row = mysqli_fetch_assoc($result)) {
						    				$nama = $row["nama"];
						    				$nim = $row["nim"];
						    				$kelas = $row["kelas"];
						    				$angkatan = $row["angkatan"];

						    				echo "
						    					<li><a class='dropdown-item' href='index.php?id=".$nim."'>Mahasiswa ".$i++."</a></li>
						    				";
						    			}
						    		}
						    	?>
						  	</ul>
              			</div>
            		</div>
          		</div>
	          	<div class="col-sm-8">
	            	<div class="card p-4">
	              		<div class="card-body">
			                <h5 class="card-tittle">Hallo Namaku</h5>
			                <hr />
			                <table>
				                <?php
				                	ini_set("display_errors", "Off");
				                	
				                	if (isset($sql) && $nim = $id) {
				                		$sql = "SELECT * FROM user WHERE nim = $id";
				                		$result = mysqli_query($connect, $sql);

				                		if ($result) {
				                			while ($row = mysqli_fetch_assoc($result)) {
				                				$nama = $row["nama"];
							    				$nim = $row["nim"];
							    				$kelas = $row["kelas"];
							    				$angkatan = $row["angkatan"];

							    				echo "
								                	<tr>
								                		<td><p class='card-text'>Nama</p></td>
								                		<td><p class='card-text' style='padding-left:10px; padding-right:10px;'>:</p></td>
								                		<td>".$nama."</td>
								                	</tr>
								                	<tr>
								                		<td><p class='card-text'>NIM</p></td>
								                		<td><p class='card-text' style='padding-left:10px; padding-right:10px;'>:</p></td>
								                		<td>".$nim."</td>
								                	</tr>
								                	<tr>
								                		<td><p class='card-text'>Kelas</p></td>
								                		<td><p class='card-text' style='padding-left:10px; padding-right:10px;'>:</p></td>
								                		<td>".$kelas."</td>
								                	</tr>
								                	<tr>
								                		<td><p class='card-text'>Angkatan</p></td>
								                		<td><p class='card-text' style='padding-left:10px; padding-right:10px;'>:</p></td>
								                		<td>".$angkatan."</td>
								                	</tr>
							    				";
				                			}
				                		}
				                	} else {
				                		echo "
				                			<tr>
						                		<td><p class='card-text'>Nama</p></td>
						                		<td><p class='card-text' style='padding-left:10px; padding-right:10px;'>:</p></td>
						                		<td>-</td>
						                	</tr>
						                	<tr>
						                		<td><p class='card-text'>NIM</p></td>
						                		<td><p class='card-text' style='padding-left:10px; padding-right:10px;'>:</p></td>
						                		<td>-</td>
						                	</tr>
						                	<tr>
						                		<td><p class='card-text'>Kelas</p></td>
						                		<td><p class='card-text' style='padding-left:10px; padding-right:10px;'>:</p></td>
						                		<td>-</td>
						                	</tr>
						                	<tr>
						                		<td><p class='card-text'>Angkatan</p></td>
						                		<td><p class='card-text' style='padding-left:10px; padding-right:10px;'>:</p></td>
						                		<td>-</td>
						                	</tr>
				                		";
				                	}
				                ?>
			                </table>                
	              		</div>
	            	</div>
	          	</div>
        	</div>
      	</div>
    </div>

    <?php include "footer.php" ?>

	
	<script src="assets/js/bootstrap.bundle.min.js"></script>
    <script src="https://cdn.jsdelivr.net/npm/@popperjs/core@2.11.8/dist/umd/popper.min.js" integrity="sha384-I7E8VVD/ismYTF4hNIPjVp/Zjvgyol6VFvRkX/vR+Vc4jQkC+hVqc2pM8ODewa9r" crossorigin="anonymous"></script>
	<script src="https://cdn.jsdelivr.net/npm/bootstrap@5.3.3/dist/js/bootstrap.min.js" integrity="sha384-0pUGZvbkm6XF6gxjEnlmuGrJXVbNuzT9qBBavbLwCsOGabYfZo0T0to5eqruptLy" crossorigin="anonymous"></script>
  </body>
</html>