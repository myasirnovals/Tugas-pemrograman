<?php

namespace App\Http\Controllers;

use Illuminate\Foundation\Auth\Access\AuthorizesRequests;
use Illuminate\Foundation\Validation\ValidatesRequests;
use Illuminate\Routing\Controller as BaseController;

class Controller extends BaseController
{
    use AuthorizesRequests, ValidatesRequests;

    public function index()
    {
        return view('pelanggan.page.home', [
            'title' => 'Home',
        ]);
    }

    public function product()
    {
        return view('pelanggan.page.product', [
            'title' => 'Product',
        ]);
    }

    public function transaksi()
    {
        return view('pelanggan.page.transaksi', [
            'title' => 'transaksi',
        ]);
    }

    public function aboutUs()
    {
        return view('pelanggan.page.aboutUs', [
            'title' => 'aboutUs',
        ]);
    }
}
