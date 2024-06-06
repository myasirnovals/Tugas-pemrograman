<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=\, initial-scale=1.0">
    {{-- cdn bootsrap 5 css--}}
    <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.0.2/dist/css/bootstrap.min.css" rel="stylesheet" integrity="sha384-EVSTQN3/azprG1Anm3QDgpJLIm9Nao0Yz1ztcQTwFspd3yD65VohhpuuCOmLASjC" crossorigin="anonymous"> 
    {{-- cdn font awesome --}}
    <link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/6.5.2/css/all.min.css" integrity="sha512-SnH5WK+bZxgPHs44uWIX+LLJAJ9/2PkPKZ5QiAj6Ta86w+fsb2TkcmfRyVX3pBnMFcV7oQPJkl9QevSCWr3W6A==" crossorigin="anonymous" referrerpolicy="no-referrer" />
    <title>Belanjaku | {{ $title }}</title>
</head>

<body>
    <main>
        <header>
            <nav class="navbar navbar-expand-lg navbar-dark bg-warning">
                <div class="container">
                  <a class="navbar-brand" href="#">Belanjaku</a>
                  <button class="navbar-toggler" type="button" data-bs-toggle="collapse" data-bs-target="#navbarSupportedContent" aria-controls="navbarSupportedContent" aria-expanded="false" aria-label="Toggle navigation">
                    <span class="navbar-toggler-icon"></span>
                  </button>
                  <div class="collapse navbar-collapse justify-content-end gap-3" id="navbarSupportedContent">
                    <ul class="navbar-nav gap-3">
                      <li class="nav-item ">
                        <a class="nav-link active fs-5" aria-current="page" href="#">Home</a>
                      </li>
                      <li class="nav-item">
                        <a class="nav-link fs-5" href="#">Product</a>
                      </li>
                      <li class="nav-item">
                        <a class="nav-link fs-5" href="#">About Us</a>
                      </li>
                      
                    </ul>
                    <div class="d-flex gap-4 align-items-center" >
                        <button class="btn btn-primary" type="button">Login | Register</button>
                        <a href="#" class="fs-5">
                            <i class="fa-solid fa-bag-shopping text-white"></i>                    
                        </a>
                    </div>
                  </div>
                </div>
              </nav>
        </header>

    </main>
</body>
{{-- cdn bootstrap 5 js --}}
<script src="https://cdn.jsdelivr.net/npm/@popperjs/core@2.9.2/dist/umd/popper.min.js" integrity="sha384-IQsoLXl5PILFhosVNubq5LC7Qb9DXgDA9i+tQ8Zj3iwWAwPtgFTxbJ8NT4GN1R8p" crossorigin="anonymous"></script>
<script src="https://cdn.jsdelivr.net/npm/bootstrap@5.0.2/dist/js/bootstrap.min.js" integrity="sha384-cVKIPhGWiC2Al4u+LWgxfKTRIcfu0JTxR+EQDz/bgldoEyl4H0zUF0QKbrJ0EcQF" crossorigin="anonymous"></script>
</html>
