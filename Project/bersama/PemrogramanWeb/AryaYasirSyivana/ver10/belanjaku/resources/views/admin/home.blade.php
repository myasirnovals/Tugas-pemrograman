<!DOCTYPE html>
<html lang="en">
<head>
    <!-- Required meta tags -->
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1, shrink-to-fit=no">
    <title>Belanjaku Admin</title>
    <!-- CSS -->
    @include('admin.css')
</head>
<body>
<!-- container start -->
<div class="container-scroller">

    <!-- sidebar start -->
    @include('admin.sidebar')
    <!-- sidebar ends -->

    <div class="container-fluid page-body-wrapper">

        <!-- header start -->
        @include('admin.header')
        <!-- header ends -->

        <!-- body of content start -->
        @include('admin.body')
        <!-- body of content ends -->

    </div>
</div>
<!-- container ends -->
<!-- Script JS -->
@include('admin.script')
</body>
</html>
