<?php

use Illuminate\Support\Facades\Route;

// Route::get('/', function () {
//     return view('welcome');
// });

Route::get('/', function () {
    return view('hello');
})->name('hello');

Route::get('/about', function () {
    return view('about');
})->name('about');

Route::get('/contact', function () {
    return view('contact');
})->name('contact');

Route::get('/services', function () {
    return view('services');
})->name('services');

Route::get('/blog', function () {
    return view('blog');
})->name('blog');

Route::get('/users', function () {
    $users = [
        ['id' => 1, 'name' => 'John Doe', 'email' => 'john@example.com'],
        ['id' => 2, 'name' => 'Jane Smith', 'email' => 'jane@example.com'],
        ['id' => 3, 'name' => 'Bob Johnson', 'email' => 'bob@example.com'],
        ['id' => 4, 'name' => 'Alice Williams', 'email' => 'alice@example.com']
    ];
    return view('users', ['users' => $users]);
})->name('users');

Route::get('/users/{id}', function ($id) {
    $users = [
        ['id' => 1, 'name' => 'John Doe', 'email' => 'john@example.com'],
        ['id' => 2, 'name' => 'Jane Smith', 'email' => 'jane@example.com'],
        ['id' => 3, 'name' => 'Bob Johnson', 'email' => 'bob@example.com'],
        ['id' => 4, 'name' => 'Alice Williams', 'email' => 'alice@example.com']
    ];
    $user = collect($users)->firstWhere('id', $id);
    if (!$user) {
        abort(404);
    }
    return view('user', ['user' => $user]);
})->name('user');