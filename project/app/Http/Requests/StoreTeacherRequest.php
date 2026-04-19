<?php

namespace App\Http\Requests;

use Illuminate\Foundation\Http\FormRequest;

class StoreTeacherRequest extends FormRequest
{
    /**
     * Разрешаем использование этого запроса (обязательно true!)
     */
    public function authorize(): bool
    {
        return true; 
    }

    /**
     * Правила валидации
     */
    public function rules(): array
    {
        return [
            'name' => 'required|string|min:2|max:50',
            'lastname' => 'required|string|min:2|max:50',
            'email' => 'required|email|unique:teachers,email',
        ];
    }

    /**
     * (Опционально) Кастомные сообщения об ошибках
     */
    public function messages(): array
    {
        return [
            'name.required' => 'Имя обязательно для заполнения.',
            'email.unique' => 'Этот email уже зарегистрирован в системе.',
            'email.email' => 'Введите корректный email адрес.',
        ];
    }
}