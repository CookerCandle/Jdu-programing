<?php

namespace App\Http\Controllers;

use App\Models\Student;
use Illuminate\Http\Request;

class StudentController extends Controller
{
    public function create()
    {
        return view('students.create');
    }

    public function store(Request $request)
    {
        // 1. Валидация данных
        $validated = $request->validate([
            'name' => 'required|string|min:3|max:255',
            'lastname' => 'required|string|min:5|max:255',
        ]);

        // 2. Создание записи
        Student::create($validated);

        // 3. Редирект обратно с сообщением
        return redirect()->route('students.create')->with('success', 'Студент успешно добавлен!');
    }
}
