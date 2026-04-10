<x-layouts.base>
<div class="min-h-screen bg-gray-100 flex items-center justify-center p-6">
    <div class="bg-white p-8 rounded-xl shadow-lg w-full max-w-md">
        <h2 class="text-2xl font-bold mb-6 text-gray-800">Добавить студента</h2>

        @if(session('success'))
            <div class="mb-4 p-3 bg-green-100 text-green-700 rounded-lg border border-green-200">
                {{ session('success') }}
            </div>
        @endif

        <form action="{{ route('students.store') }}" method="POST">
            @csrf
            
            <div class="mb-4">
                <label class="block text-gray-700 text-sm font-bold mb-2">Имя</label>
                <input type="text" name="name" 
                       class="w-full px-4 py-2 border rounded-lg focus:ring-2 focus:ring-indigo-500 outline-none @error('name') border-red-500 @enderror"
                       value="{{ old('name') }}">
                @error('name') <span class="text-red-500 text-xs">{{ $message }}</span> @enderror
            </div>

            <div class="mb-6">
                <label class="block text-gray-700 text-sm font-bold mb-2">Фамилия</label>
                <input type="text" name="lastname" 
                       class="w-full px-4 py-2 border rounded-lg focus:ring-2 focus:ring-indigo-500 outline-none @error('lastname') border-red-500 @enderror"
                       value="{{ old('lastname') }}">
                @error('lastname') <span class="text-red-500 text-xs">{{ $message }}</span> @enderror
            </div>

            <button type="submit" 
                    class="w-full bg-indigo-600 hover:bg-indigo-700 text-white font-bold py-2 px-4 rounded-lg transition duration-300">
                Сохранить
            </button>
        </form>
    </div>
</div>
</x-layouts.base>