<?php
	session_start();
	if (isset($_SESSION['user'])) {
		header("Location: index.php");
	}
?>

<!DOCTYPE html>
<html>
<head>
	<meta charset="utf-8">
	<meta name="viewport" content="width=device-width, initial-scale=1">
	<link rel="stylesheet" type="text/css" href="../assets/css/bootstrap.min.css">
	<link rel="icon" type="image/icon" href="../assets/image/logo2.png">
	<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/6.5.2/css/all.min.css" integrity="sha512-SnH5WK+bZxgPHs44uWIX+LLJAJ9/2PkPKZ5QiAj6Ta86w+fsb2TkcmfRyVX3pBnMFcV7oQPJkl9QevSCWr3W6A==" crossorigin="anonymous" referrerpolicy="no-referrer" />
	<title>Apotek Online</title>
</head>
<body style="background-color: lightgray;">
	<div class="container m-5">

		<?php
			if (isset($_POST['submit'])) {
				$nama = $_POST['nama'];
				$email = $_POST['email'];
				$password = $_POST['password'];
				$confirm_password = $_POST['confirm_password'];

				$passwordHash = password_hash($password, PASSWORD_DEFAULT);
				$errors = array();

				if (empty($nama) AND empty($email) AND empty($password) AND empty($confirm_password)) {
					array_push($errors, "Semua field tidak boleh kosong");
				}

				else if (empty($email)) {
					array_push($errors, "Email tidak boleh kosong");
				}

				else if (empty($password)) {
					array_push($errors, "Password tidak boleh kosong");
				}

				else if (!filter_var($email, FILTER_VALIDATE_EMAIL) AND !empty($email)) {
					array_push($errors, "Email tidak valid");
				}

				else if (strlen($password) < 8) {
					array_push($errors, "Password harus lebih dari 8");
				}

				else if ($password !== $confirm_password) {
					array_push($errors, "Password tidak sama");
				}

				require_once "../databases/db.php";
				$sql = "SELECT * FROM user WHERE email = '$email'";
				$result = mysqli_query($connect, $sql);
				$rowCount = mysqli_num_rows($result);

				if ($rowCount>0) {
					array_push($errors, "Email sudah ada");
				}

				if (count($errors)>0) {
					foreach ($errors as $error) {
						echo "<div class='alert alert-danger'>$error</div>";
					}
				} else {
					$sql = "INSERT INTO user (nama, email, password) VALUES (?,?,?)";
					$stmt = mysqli_stmt_init($connect);
					$preparestmt = mysqli_stmt_prepare($stmt, $sql);

					if ($preparestmt) {
						mysqli_stmt_bind_param($stmt, "sss", $nama, $email, $passwordHash);
						mysqli_stmt_execute($stmt);
						header("Location: login.php");
					} else {
						die("Ada kesalahan yang terjadi");
					}
				}
			}
		?>

		<div class="row">
			<div class="col-3"></div>
			<div class="col-6">
				<form action="register.php" method="post">
					<div class="container border bg-light p-3 rounded">
						<img src="../assets/image/logo2.png" class="w-25 mx-auto d-block mt-2 mb-5">
						<div class="form-group">
							<input type="text" class="form-control" name="role" value="0" hidden>
						</div>
						<div class="mb-3">
						    <label for="nama" class="form-label">Nama</label>
						    <div class="input-group mb-3">
								<span class="input-group-text" id="basic-addon1"><i class="fa-solid fa-user"></i></span>
							  	<input type="text" class="form-control" name="nama" id="nama" placeholder="Masukan nama anda" width="200px">
							</div>
						  </div>
						<div class="mb-3">
						    <label for="email" class="form-label">Email address</label>
						    <div class="input-group mb-3">
								<span class="input-group-text" id="basic-addon1"><i class="fa-solid fa-envelope"></i></span>
							  	<input type="email" class="form-control" name="email" id="email" placeholder="Masukan email anda" width="200px">
							</div>
						  </div>
						  <div class="mb-3">
						    <label for="password" class="form-label">Password</label>
						    <div class="input-group mb-3">
								<span class="input-group-text" id="basic-addon1"><i class="fa-solid fa-key"></i></span>
							  	<input type="password" class="form-control" name="password" id="password" placeholder="Masukan password anda" width="200px">
							</div>
						  </div>
						  <div class="mb-3">
						    <label for="confirm_password" class="form-label">Confirm password</label>
						    <div class="input-group mb-3">
								<span class="input-group-text" id="basic-addon1"><i class="fa-solid fa-key"></i></span>
							  	<input type="password" class="form-control" name="confirm_password" id="confirm_password" placeholder="confirm password anda" width="200px">
							</div>
						  </div>					  
						  <div class="text mb-3">
						  	<a href="login.php">Already have an account?</a>
						  </div>
						  <div class="form-btn">
						  	<input type="submit" name="submit" class="btn btn-primary" value="Sign Up">
						  	<a href="../index.php" class="btn btn-danger">Cancel</a>
						  </div>
					</div>
				</form>
			</div>
			<div class="col-3"></div>
		</div>
	</div>
	
	<script type="text/javascript" src="../assets/js/bootstrap.bundle.min.js"></script>
</body>
</html>