<x-app-layout>
    <x-slot name="header">
        <h2 class="font-semibold text-xl text-gray-800 leading-tight">
            {{ __('Добавить учителя') }}
        </h2>
    </x-slot>

    <div class="flex flex-col justify-center items-center py-12 px-4 sm:px-6 lg:px-8">
        
        <div class="w-full max-w-md">
            
            <div class="mb-4">
                <a href="{{ route('teachers.index') }}" class="text-sm font-medium text-gray-500 hover:text-indigo-600 flex items-center transition-colors">
                    <svg class="w-4 h-4 mr-1" fill="none" stroke="currentColor" viewBox="0 0 24 24"><path d="M15 19l-7-7 7-7" stroke-width="2" stroke-linecap="round" stroke-linejoin="round"></path></svg>
                    Назад к списку
                </a>
            </div>

            <div class="bg-white rounded-2xl shadow-xl border border-gray-100 overflow-hidden">
                <div class="p-8">
                    <h3 class="text-xl font-bold text-gray-900 mb-6">Новый преподаватель</h3>
                    
                    <form action="{{ route('teachers.store') }}" method="POST">
                        @csrf

                        <div class="space-y-5">
                            <div>
                                <label for="name" class="block text-sm font-semibold text-gray-700 mb-1">Имя</label>
                                <input type="text" name="name" id="name" 
                                       value="{{ old('name') }}"
                                       class="block w-full px-4 py-2.5 rounded-xl border @error('name') border-red-300 text-red-900 @else border-gray-200 @enderror focus:ring-2 focus:ring-indigo-500 focus:border-indigo-500 transition-all outline-none"
                                       placeholder="Имя">
                                @error('name') <p class="mt-1 text-xs text-red-600">{{ $message }}</p> @enderror
                            </div>

                            <div>
                                <label for="lastname" class="block text-sm font-semibold text-gray-700 mb-1">Фамилия</label>
                                <input type="text" name="lastname" id="lastname" 
                                       value="{{ old('lastname') }}"
                                       class="block w-full px-4 py-2.5 rounded-xl border @error('lastname') border-red-300 @else border-gray-200 @enderror focus:ring-2 focus:ring-indigo-500 focus:border-indigo-500 transition-all outline-none"
                                       placeholder="Фамилия">
                                @error('lastname') <p class="mt-1 text-xs text-red-600">{{ $message }}</p> @enderror
                            </div>

                            <div>
                                <label for="email" class="block text-sm font-semibold text-gray-700 mb-1">Email</label>
                                <input type="email" name="email" id="email" 
                                       value="{{ old('email') }}"
                                       class="block w-full px-4 py-2.5 rounded-xl border @error('email') border-red-300 @else border-gray-200 @enderror focus:ring-2 focus:ring-indigo-500 focus:border-indigo-500 transition-all outline-none"
                                       placeholder="teacher@jdu.uz">
                                @error('email') <p class="mt-1 text-xs text-red-600">{{ $message }}</p> @enderror
                            </div>
                        </div>

                        <div class="mt-8">
                            <button type="submit" class="w-full py-3 bg-indigo-600 hover:bg-indigo-700 text-white font-bold rounded-xl shadow-lg shadow-indigo-100 transition-all active:scale-[0.98]">
                                Создать учителя
                            </button>
                            <button type="reset" class="w-full mt-3 py-2 text-sm font-medium text-gray-400 hover:text-gray-600 transition-colors">
                                Очистить поля
                            </button>
                        </div>
                    </form>
                </div>
            </div>
            
        </div>
    </div>
</x-app-layout>