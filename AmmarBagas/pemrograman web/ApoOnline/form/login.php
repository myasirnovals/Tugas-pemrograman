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
				$email = $_POST['email'];
				$password = $_POST['password'];
				require_once "../databases/db.php";

				$sql = "SELECT * FROM user WHERE email = '$email'";
				$result = mysqli_query($connect, $sql);
				$user = mysqli_fetch_array($result);

				if ($user) {
					if (password_verify($password, $user['password']) && $user["role"] == 1) {
						session_start();
						$_SESSION['user'] = true;
						header("Location: ../admin/admin.php");
						die();
					
					} else if (password_verify($password, $user['password']) && $user["role"] == 2) {
						session_start();
						$_SESSION['user'] = true;
						header("Location: ../karyawan/karyawan.php");
						die();
					
					} else if (password_verify($password, $user['password']) && $user["role"] == 0) {
						session_start();
						$_SESSION['user'] = true;
						header("Location: ../index.php");
						die();
					
					} else {
						echo "<div class='alert alert-danger'>Password tidak valid</div>";
					}
				} else {
					echo "<div class='alert alert-danger'>Email tidak valid</div>";
				}
			}
		?>

		<div class="row">
			<div class="col-3"></div>
			<div class="col-6">
				<form action="login.php" method="post">
					<div class="container border bg-light p-3 rounded">
						<img src="../assets/image/logo2.png" class="w-25 mx-auto d-block mt-2 mb-5">
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
						  <div class="text mb-3">
						  	<a href="register.php">Don't have an account, register now!</a>
						  </div>
						  <div class="form-btn">
							  <input type="submit" name="submit" class="btn btn-primary" value="Log In">
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