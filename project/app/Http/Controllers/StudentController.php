<?php

namespace App\Http\Controllers;

use Illuminate\Http\Request;

use App\Models\Student;

use Illuminate\Support\Facades\Gate;

use Illuminate\Support\Facades\Mail;
use App\Mail\StudentPosted;
use App\Mail\StudentUpdated;
use App\Mail\StudentDeleted;

class StudentController extends Controller
{
    public function index()
    {
        $students = Student::paginate(6);
        return view('students.index', compact('students'));
    }

    public function show($id)
    {
        $student = Student::findOrFail($id);
        return view('students.show', compact('student'));
    }

    public function create()
    {
        return view('students.create');
    }

    public function store(Request $request)
    {
        $request->validate([
            'firstname' => 'required|string|min:2|max:255',
            'lastname' => 'required|string|min:2|max:255',
        ]);

        $data = $request->all();
        $data['user_id'] = auth()->id();

        Student::create($data);

        Mail::to($request->user())->send(new StudentPosted($data['firstname']));

        return redirect()->route('students.create')->with('success', 'Student created successfully.');
    }

    public function edit($id)
    {
        $student = Student::findOrFail($id);
        return view('students.edit', compact('student'));
    }

    public function update(Request $request, $id)
    {
        $student = Student::findOrFail($id);

        // Gate::authorize('update-student', $student);
        $this->authorize('update', $student);

        $request->validate([
            'firstname' => 'required|string|min:2|max:255',
            'lastname' => 'required|string|min:2|max:255',
        ]);

        $student->update($request->all());

        Mail::to($request->user())->send(new StudentUpdated($student->firstname));

        return redirect()->route('students.edit', $id)->with('success', 'Student updated successfully.');
    }

    public function destroy(Request $request, $id)
    {
        $student = Student::findOrFail($id);
        $student->delete();

        Mail::to($request->user())->send(new StudentDeleted($student->firstname));

        return redirect()->route('students.index')->with('success', 'Student deleted successfully.');
    }
}
