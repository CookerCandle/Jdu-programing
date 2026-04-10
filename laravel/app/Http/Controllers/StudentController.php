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
        $validated = $request->validate([
            'name' => 'required|string|min:3|max:255',
            'lastname' => 'required|string|min:5|max:255',
        ]);

        Student::create($validated);

        return redirect()->route('students.create')->with('success', 'Студент успешно добавлен!');
    }

    public function update(Request $request, Student $student) 
    {
        $validated = $request->validate([
            'name' => 'required|string|min:3|max:255',
            'lastname' => 'required|string|min:5|max:255',
        ]);

        $student->update($validated);

        return redirect()->route('student', $student)->with('success', 'Студент успешно обновлен!');
                 
    }

    public function index()
    {
        $students = Student::paginate(6);
        return view('students.index', compact('students'));
    }

    public function show(Student $student)
    {
        return view('students.show', compact('student'));
    }

    public function destroy(Student $student)
    {
        $student->delete();
        return redirect()->route('students')->with('success', 'Студент успешно удален!');
    }
}
