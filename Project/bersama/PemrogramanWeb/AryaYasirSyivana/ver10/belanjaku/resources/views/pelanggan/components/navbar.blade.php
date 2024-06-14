<nav class="navbar navbar-expand-lg navbar-dark bg-warning">
    <div class="container">
        <a class="navbar-brand" href="#">Belanjaku</a>
        <button class="navbar-toggler" type="button" data-bs-toggle="collapse" data-bs-target="#navbarSupportedContent"
                aria-controls="navbarSupportedContent" aria-expanded="false" aria-label="Toggle navigation">
            <span class="navbar-toggler-icon"></span>
        </button>
        <div class="collapse navbar-collapse justify-content-end gap-3" id="navbarSupportedContent">
            <ul class="navbar-nav gap-3">
                <li class="nav-item ">
                    <a class="nav-link active fs-5" aria-current="page" href="/">Home</a>
                </li>
                <li class="nav-item">
                    <a class="nav-link fs-5" href="/product">Product</a>
                </li>
                <li class="nav-item">
                    <a class="nav-link fs-5" href="/aboutUs">About Us</a>
                </li>
                @if(Route::has('login'))
                    @auth
                        <x-app-layout>

                        </x-app-layout>
                    @else
                        <li class="nav-item">
                            <a class="nav-link fs-5" href="{{ route('login') }}" id="btn-login">Login</a>
                        </li>
                        <li class="nav-item">
                            <a class="nav-link fs-5" href="{{ route('register') }}" id="btn-register">Register</a>
                        </li>
                    @endauth
                @endif
            </ul>
        </div>
    </div>
</nav>
