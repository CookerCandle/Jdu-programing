<?php

namespace App\Http\Controllers;

use App\Http\Requests\StoreTeacherRequest;
use App\Http\Requests\UpdateTeacherRequest;
use Illuminate\Http\Request;
use App\Models\Teacher;

class TeacherController extends Controller
{
    /**
     * Display a listing of the resource.
     */
    public function index()
    {
        $teachers = Teacher::paginate(6);
        return view('teachers.index', compact('teachers'));
    }

    /**
     * Show the form for creating a new resource.
     */
    public function create()
    {
        return view('teachers.create');
    }

    /**
     * Store a newly created resource in storage.
     */
    public function store(StoreTeacherRequest $request)
    {
        Teacher::create([
            'first_name' => $request->name,
            'last_name' => $request->lastname,
            'email' => $request->email,
        ]);

        return redirect()->route('teachers.index')->with('success', 'Учитель добавлен!');
    }

    /**
     * Display the specified resource.
     */
    public function show(Teacher $teacher)
    {
        return view('teachers.show', compact('teacher'));
    }

    /**
     * Show the form for editing the specified resource.
     */
    public function edit(Teacher $teacher)
    {
        return view('teachers.edit', compact('teacher'));
    }

    /**
     * Update the specified resource in storage.
     */
    public function update(UpdateTeacherRequest $request, Teacher $teacher)
    {
        $teacher->update([
            'first_name' => $request->name,
            'last_name' => $request->lastname,
            'email' => $request->email,
        ]);

        return redirect()->route('teachers.index')->with('success', 'Учитель обновлен!');
    }

    /**
     * Remove the specified resource from storage.
     */
    public function destroy(Teacher $teacher)
    {
        $teacher->delete();
        return redirect()->route('teachers.index')->with('success', 'Учитель удален');
    }
}
