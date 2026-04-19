<?php

namespace App\Http\Requests;

use Illuminate\Contracts\Validation\ValidationRule;
use Illuminate\Foundation\Http\FormRequest;

class UpdateTeacherRequest extends FormRequest
{
    /**
     * Determine if the user is authorized to make this request.
     */
    public function authorize(): bool
    {
        return true;
    }

    /**
     * Get the validation rules that apply to the request.
     *
     * @return array<string, ValidationRule|array<mixed>|string>
     */
    public function rules(): array
    {
        return [
            'name' => 'required|string|max:255',
            'lastname' => 'required|string|max:255',
            'email' => 'required|email|unique:teachers,email,' . $this->teacher->id,
        ];
    }

    public function messages(): array
    {
        return [
            'name.required' => 'Имя обязательно для заполнения.',
            'lastname.required' => 'Фамилия обязательна для заполнения.',
            'email.unique' => 'Этот email уже зарегистрирован в системе.',
            'email.email' => 'Введите корректный email адрес.',
        ];
    }
}
