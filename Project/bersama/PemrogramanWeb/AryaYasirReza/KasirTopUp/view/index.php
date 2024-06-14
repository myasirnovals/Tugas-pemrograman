<!doctype html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport"
          content="width=device-width, user-scalable=no, initial-scale=1.0, maximum-scale=1.0, minimum-scale=1.0">
    <meta http-equiv="X-UA-Compatible" content="ie=edge">
    <title>Top Up Store</title>
</head>
<body>
<script>
    let verify = confirm("Are you a member?");

    if (verify === true) {
        window.location.href = "login.php";
    } else {
        window.location.href = "user/guest.php";
    }
</script>
</body>
</html>