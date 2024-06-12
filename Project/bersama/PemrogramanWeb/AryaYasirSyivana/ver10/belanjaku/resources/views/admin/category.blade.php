<!DOCTYPE html>
<html lang="en">
<head>
    <!-- Required meta tags -->
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1, shrink-to-fit=no">
    <title>Belanjaku</title>
    <!-- CSS External -->
    @include('admin.css')

    <!-- CSS Internal -->
    <style>
        .div-center {
            text-align: center;
            padding-top: 40px;
        }

        .h2-fonts {
            font-size: 40px;
            padding-bottom: 30px;
        }

        .input-category {
            color: black;
        }
    </style>
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
        <div class="main-panel">
            <div class="content-wrapper">
                @if(session()->has('message'))
                    <div class="alert alert-success">
                        <button type="button" class="close" data-dismiss="alert" aria-hidden="true">X</button>
                        {{ session()->get('message') }}
                    </div>
                @endif
                <div class="div-center">
                    <h2 class="h2-fonts">Add Category</h2>
                    <form action="{{ url('/add_category') }}" method="post">
                        @csrf
                        <input type="text" class="input-category" name="category" id="category"
                               placeholder="write category name">
                        <input type="submit" class="btn btn-outline-primary ml-3" value="Add Category">
                    </form>
                </div>
                <div class="container mt-5">
                    <table class="table table-bordered">
                        <thead>
                        <tr>
                            <th>Category Name</th>
                            <th>Action</th>
                        </tr>
                        </thead>
                        <tbody>
                        @foreach($data as $item)
                            <tr>
                                <td>{{ $item->category_name }}</td>
                                <td><a href="{{ url('delete_category', $item->id) }}" class="btn btn-danger"
                                       onclick="return confirm('Are you sure to delete this')">Delete</a></td>
                            </tr>
                        @endforeach
                        </tbody>
                    </table>
                </div>
            </div>
        </div>
        <!-- body of content ends -->

    </div>
</div>
<!-- container ends -->
<!-- Script JS -->
@include('admin.script')
</body>
</html>
