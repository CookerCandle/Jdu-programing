<?php

use Illuminate\Support\Facades\Route;

Route::get('/', function () {
    return "welcome";
});

Route::get('/contact', function () {
    return view('static.contact');
});
