<?php
  include "databases/db.php";
?>

<div class='container py-5'>
  <div class='row mt-4'>
    <?php
      $sql = "SELECT * FROM produk";
      $result = mysqli_query($connect, $sql);

      if ($result) {
        while ($row = mysqli_fetch_assoc($result)) {
          $id = $row['id'];
          $nama_produk = $row['nama_produk'];
          $keterangan_produk = $row['keterangan_produk'];
          $harga = number_format($row["harga"], 0, ",", ".");
          $gambar_produk = $row['gambar_produk'];
          $tanggal_exp = $row['tanggal_exp'];

          echo "
            <div class='col-4'>
              <div class='card mb-5' style='width: 18rem;'>
                <img src='assets/imageProduct/".$gambar_produk."' class='card-img-top' alt='...'>
                <div class='card-body'>
                  <h5 class='card-title'>".$nama_produk."</h5>
                  <p class='card-text'>".$keterangan_produk."</p>
                  <a href='#' class='btn btn-primary'>See the product!</a>
                </div>
              </div>
            </div>
          ";
        }
      }
    ?>
    
  </div>
</div>

<!-- <div class="row">
  <div class="col-4">
    <div class="card" style="width: 18rem;">
      <img src="assets/imageProduct/produk-1.png" class="card-img-top" alt="...">
      <div class="card-body">
        <h5 class="card-title"></h5>
        <p class="card-text">Some quick example text to build on the card title and make up the bulk of the card's content.</p>
        <a href="#" class="btn btn-primary">See the product!</a>
      </div>
    </div>
  </div>
  <div class="col-4">
    <div class="card" style="width: 18rem;">
      <img src="assets/imageProduct/produk-2.png" class="card-img-top" alt="...">
      <div class="card-body">
        <h5 class="card-title">Card title</h5>
        <p class="card-text">Some quick example text to build on the card title and make up the bulk of the card's content.</p>
        <a href="#" class="btn btn-primary">See the product!</a>
      </div>
    </div>
  </div>
  <div class="col-4">
    <div class="card" style="width: 18rem;">
      <img src="assets/imageProduct/produk-3.png" class="card-img-top" alt="...">
      <div class="card-body">
        <h5 class="card-title">Card title</h5>
        <p class="card-text">Some quick example text to build on the card title and make up the bulk of the card's content.</p>
        <a href="#" class="btn btn-primary">See the product!</a>
      </div>
    </div>
  </div>
</div>

<div class="row mt-5">
  <div class="col-4">
    <div class="card" style="width: 18rem;">
      <img src="assets/imageProduct/produk-4.png" class="card-img-top" alt="...">
      <div class="card-body">
        <h5 class="card-title">Card title</h5>
        <p class="card-text">Some quick example text to build on the card title and make up the bulk of the card's content.</p>
        <a href="#" class="btn btn-primary">See the product!</a>
      </div>
    </div>
  </div>
  <div class="col-4">
    <div class="card" style="width: 18rem;">
      <img src="assets/imageProduct/produk-5.png" class="card-img-top" alt="...">
      <div class="card-body">
        <h5 class="card-title">Card title</h5>
        <p class="card-text">Some quick example text to build on the card title and make up the bulk of the card's content.</p>
        <a href="#" class="btn btn-primary">See the product!</a>
      </div>
    </div>
  </div>
  <div class="col-4">
    <div class="card" style="width: 18rem;">
      <img src="assets/imageProduct/produk-6.png" class="card-img-top" alt="...">
      <div class="card-body">
        <h5 class="card-title">Card title</h5>
        <p class="card-text">Some quick example text to build on the card title and make up the bulk of the card's content.</p>
        <a href="#" class="btn btn-primary">See the product!</a>
      </div>
    </div>
  </div>
</div>

<div class="row mt-5">
  <div class="col-4">
    <div class="card" style="width: 18rem;">
      <img src="assets/imageProduct/produk-7.png" class="card-img-top" alt="...">
      <div class="card-body">
        <h5 class="card-title">Card title</h5>
        <p class="card-text">Some quick example text to build on the card title and make up the bulk of the card's content.</p>
        <a href="#" class="btn btn-primary">See the product!</a>
      </div>
    </div>
  </div>
  <div class="col-4">
    <div class="card" style="width: 18rem;">
      <img src="assets/imageProduct/produk-8.png" class="card-img-top" alt="...">
      <div class="card-body">
        <h5 class="card-title">Card title</h5>
        <p class="card-text">Some quick example text to build on the card title and make up the bulk of the card's content.</p>
        <a href="#" class="btn btn-primary">See the product!</a>
      </div>
    </div>
  </div>
  <div class="col-4">
    <div class="card" style="width: 18rem;">
      <img src="assets/imageProduct/produk-9.png" class="card-img-top" alt="...">
      <div class="card-body">
        <h5 class="card-title">Card title</h5>
        <p class="card-text">Some quick example text to build on the card title and make up the bulk of the card's content.</p>
        <a href="#" class="btn btn-primary">See the product!</a>
      </div>
    </div>
  </div>
</div> -->