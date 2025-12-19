<?php

use Illuminate\Support\Facades\Route;

Route::get('/', function () {
    return view('static.home');
});

Route::get('/contact', function () {
    return view('static.contact');
});

Route::get('/about', function () {
    return view('static.about');
});

Route::get('/forum', function () {
    return view('static.forum');
});

Route::get('/team', function () {
    return view('static.team');
});