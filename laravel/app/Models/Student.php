<?php

namespace App\Models;

use Illuminate\Database\Eloquent\Model;
use Illuminate\Database\Eloquent\Factories\HasFactory;

class Student extends Model {

    use HasFactory;

    public static function find($id, $columns = ['*']) {
        $students = self::all();
        return collect($students)->firstWhere('id', $id) ?? null;
    }
}

