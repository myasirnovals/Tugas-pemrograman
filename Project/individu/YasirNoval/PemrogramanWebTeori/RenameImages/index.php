<!doctype html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport"
          content="width=device-width, user-scalable=no, initial-scale=1.0, maximum-scale=1.0, minimum-scale=1.0">
    <meta http-equiv="X-UA-Compatible" content="ie=edge">
    <title>Rename Images</title>
</head>
<body>
<h1>Halo, you can use my website for rename all image for resource at android studio</h1>
<br>
<form action="uploads.php" enctype="multipart/form-data" method="post">
    <label for="position">Add word on: </label>
    <input type="radio" name="position" id="position" value="start">start
    <input type="radio" name="position" id="position" value="end"> end
    <br>
    <label for="keywords">Write your word: </label>
    <input type="text" name="keywords" id="keywords" pattern="[A-Za-z]{3,}">
    <br>
    <label for="renameImages">Rename Image</label>
    <input type="file" name="renameImages[]" id="renameImages" accept="image/*" multiple>
    <br>
    <button type="submit" name="submit" value="submit">Submit</button>
</form>
</body>
</html>