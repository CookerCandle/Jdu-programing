<?php

namespace App\Models;

use Illuminate\Database\Eloquent\Model;

class Student extends Model {

    public static function all($columns = ['*']) {
        return [
            ['id' => 1, 'name' => 'John Doe', 'email' => 'john@example.com'],
            ['id' => 2, 'name' => 'Jane Smith', 'email' => 'jane@example.com'],
            ['id' => 3, 'name' => 'Bob Johnson', 'email' => 'bob@example.com'],
            ['id' => 4, 'name' => 'Alice Williams', 'email' => 'alice@example.com']
        ];
    }

    public static function find($id, $columns = ['*']) {
        $students = self::all();
        return collect($students)->firstWhere('id', $id) ?? null;
    }
}

