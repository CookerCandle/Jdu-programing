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

Route::get('/users', function () {
    $students = Student::paginate(6);
    
    return view('users', compact('students'));
})->name('users');

Route::get('/users/{id}', function ($id) {
    $user = Student::find($id);
    if ($user) {
        return view('user', ['user' => $user]);
    } else {
        return response()->json(['message' => 'User not found'], 404);
    }
})->name('user');

Route::get('/students/create', [StudentController::class, 'create'])->name('students.create');
Route::post('/students', [StudentController::class, 'store'])->name('students.store');