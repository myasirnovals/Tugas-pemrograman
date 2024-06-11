<!DOCTYPE html>
<html data-bs-theme="light" lang="en">

<head>
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0, shrink-to-fit=no">
    <title>Register</title>
    <link rel="stylesheet" href="../assets/bootstrap/css/bootstrap.min.css">
    <link rel="stylesheet" href="../assets/css/Features-Image-images.css">
    <link rel="stylesheet" href="../assets/css/Footer-Basic-icons.css">
</head>
<body>
<section class="position-relative py-4 py-xl-5">
    <div class="container">
        <div class="row mb-5">
            <div class="col-md-8 col-xl-6 text-center mx-auto">
                <h2>Daftar Member</h2>
                <p class="w-lg-50 mt-4">Apa sih keuntungan nya jadi member. kalau jadi member itu ketika anda melakukan top
                    up pada game yang ada di website kami, secara otomatis anda akan mendapat diskon dalam pembelian dan
                    anda juga akan mendapatkan point yang bisa digunakan untuk top up pada game yang sama atau game yang
                    lainnya.</p>
            </div>
        </div>
        <div class="row d-flex justify-content-center">
            <div class="col-md-6 col-xl-4">
                <div class="card mb-5">
                    <div class="card-body d-flex flex-column align-items-center">
                        <form action="" method="post">
                            <div class="row">
                                <div class="col-6 col-sm-12">
                                    <div class="mb-3">
                                        <label for="username" class="form-label">Username:</label>
                                        <input type="text" name="username" id="username" class="form-control" required>
                                    </div>
                                    <div class="mb-3">
                                        <label for="password" class="form-label">Password:</label>
                                        <input type="password" name="password" id="password" class="form-control"
                                               required>
                                    </div>
                                    <div class="mb-3">
                                        <label for="name" class="form-label">Nama:</label>
                                        <input type="text" name="name" id="name" class="form-control" required>
                                    </div>
                                    <div class="mb-3">
                                        <label for="members" class="form-label">Member Group:</label>
                                        <select name="members" id="members" class="form-control">
                                            <option value="silver">Silver</option>
                                            <option value="gold">Gold</option>
                                            <option value="platinum">Platinum</option>
                                        </select>
                                    </div>
                                    <div class="mb-3 hiding">
                                        <label for="tgl_create" class="form-label">Tanggal Dibuat:</label>
                                        <input type="date" name="tgl_create" id="tgl_create" class="form-control"
                                               required>
                                    </div>
                                </div>
                                <div class="col-6 col-sm-12">
                                    <div class="mb-3">
                                        <label for="birthdate" class="form-label">Tanggal Lahir:</label>
                                        <input type="date" name="birthdate" id="birthdate" class="form-control"
                                               required>
                                    </div>
                                    <div class="mb-3">
                                        <label for="telp" class="form-label">Nomor telepon:</label>
                                        <input type="text" name="telp" id="telp" class="form-control" required>
                                    </div>
                                    <div class="mb-3">
                                        <label for="email" class="form-label">Email:</label>
                                        <input type="email" name="email" id="email" class="form-control" required>
                                    </div>
                                    <div class="mb-3">
                                        <label for="address" class="form-label">Alamat:</label>
                                        <textarea name="address" id="address" cols="30" rows="5"
                                                  class="form-control"></textarea>
                                    </div>
                                </div>
                            </div>
                            <div class="mb-3">
                                <button class="btn btn-primary d-block w-100" type="submit">Daftar</button>
                            </div>
                            <span class="text-muted">Sudah jadi member?</span>
                            <a href="#" class="text-decoration-none">Login now</a>
                        </form>
                    </div>
                </div>
            </div>
        </div>
    </div>
</section>
<script src="../assets/bootstrap/js/bootstrap.min.js"></script>
</body>
</html>
