<x-layouts.base>
<div class="container mx-auto p-6">
    <h2 class="text-2xl font-bold mb-6 text-gray-800">Список студентов</h2>

    <div class="grid grid-cols-1 md:grid-cols-2 lg:grid-cols-3 gap-6 mb-8">
        @foreach ($students as $student)
            <div class="bg-white rounded-xl shadow-md overflow-hidden border border-gray-100 hover:shadow-lg transition-shadow duration-300">
                <div class="p-5 flex items-center space-x-4">
                    <div class="h-12 w-12 rounded-full bg-indigo-100 flex items-center justify-center text-indigo-700 font-bold">
                        {{ substr($student->name, 0, 1) }}
                    </div>
                    <div>
                        <p class="text-lg font-semibold text-gray-900">{{ $student->name }}</p>
                        <p class="text-sm text-gray-500">ID: {{ $student->id }}</p>
                    </div>
                </div>
                <div class="bg-gray-50 px-5 py-3 border-t border-gray-100 flex justify-between items-center">
                    <span class="text-xs font-medium text-indigo-600 uppercase tracking-wider">Студент</span>
                    <a href="{{ route('user', $student->id) }}" class="text-sm text-gray-600 hover:text-indigo-600">Профиль →</a>
                </div>
            </div>
        @endforeach
    </div>

    <div class="mt-8">
        {{ $students->links() }}
    </div>
</div>
</x-layouts.base>