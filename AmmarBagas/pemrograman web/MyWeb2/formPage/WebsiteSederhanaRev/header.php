<div class="head">
	<div class="container-fluid -bg-body-color p-4">
       	<div class="row">
          	<div class="col-sm-2 text-start">
            	<a href="index.php" class="shdw"><h2 class="text-white">MyWeb</h2></a>
          	</div>
			  <div class="col-sm-6 offset-sm-4 text-right">
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
</div>