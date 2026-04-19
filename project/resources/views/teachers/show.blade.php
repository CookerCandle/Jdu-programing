<x-app-layout>
    <x-slot name="header">
        <h2 class="font-semibold text-xl text-gray-800 leading-tight">
            {{ __('Профиль учителя') }}
        </h2>
    </x-slot>

    <div class="flex justify-center items-center py-12">
        
        <div class="w-full max-w-sm bg-white rounded-2xl shadow-lg border border-gray-100 p-6">
            
            <div class="flex flex-col items-center">
                <div class="w-20 h-20 bg-indigo-100 text-indigo-600 rounded-full flex items-center justify-center text-3xl font-bold uppercase mb-4">
                    {{ mb_substr($teacher->first_name, 0, 1) }}{{ mb_substr($teacher->last_name, 0, 1) }}
                </div>
                
                <h2 class="text-xl font-bold text-gray-900">{{ $teacher->first_name }} {{ $teacher->last_name }}</h2>
                <p class="text-sm text-gray-500 mb-6">Преподаватель</p>

                <div class="w-full space-y-4 mb-8">
                    <div class="flex justify-between border-b border-gray-50 pb-2">
                        <span class="text-xs font-semibold text-gray-400 uppercase">Email</span>
                        <span class="text-sm font-medium text-gray-700">{{ $teacher->email }}</span>
                    </div>
                    <div class="flex justify-between border-b border-gray-50 pb-2">
                        <span class="text-xs font-semibold text-gray-400 uppercase">Дата</span>
                        <span class="text-sm font-medium text-gray-700">{{ $teacher->created_at->format('d.m.Y') }}</span>
                    </div>
                    <div class="flex justify-between border-b border-gray-50 pb-2">
                        <span class="text-xs font-semibold text-gray-400 uppercase">ID</span>
                        <span class="text-sm font-medium text-gray-700">{{ $teacher->id }}</span>
                    </div>
                </div>

                <div class="flex gap-3 w-full">
                    <a href="{{ route('teachers.edit', $teacher->id) }}" class="flex-1 text-center py-2 bg-gray-50 hover:bg-gray-100 text-gray-700 text-sm font-semibold rounded-lg transition-colors">
                        Редактировать
                    </a>
                    <form action="{{ route('teachers.destroy', $teacher->id) }}" method="POST" class="flex-1">
                        @csrf @method('DELETE')
                        <button type="submit" class="w-full py-2 bg-red-50 hover:bg-red-100 text-red-600 text-sm font-semibold rounded-lg transition-colors" onclick="return confirm('Удалить?')">
                            Удалить
                        </button>
                    </form>
                </div>
                
                <a href="{{ route('teachers.index') }}" class="mt-6 text-xs text-gray-400 hover:text-indigo-600 transition-colors">
                    ← Вернуться назад
                </a>
            </div>

        </div>
    </div>
</x-app-layout>