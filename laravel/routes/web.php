<?php

use Illuminate\Support\Facades\Route;
use App\Models\Student;

use App\Http\Controllers\StudentController;

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

// Students routes
Route::get('/students', [StudentController::class, 'index'])->name('students');
Route::get('/students/create', [StudentController::class, 'create'])->name('students.create');
Route::post('/student', [StudentController::class, 'store'])->name('students.store');
Route::put('/students/update/{student}', [StudentController::class, 'update'])->name('students.update');
Route::get('/student/{student}', [StudentController::class, 'show'])->name('student');
Route::delete('/students/delete/{student}', [StudentController::class, 'destroy'])->name('students.destroy');