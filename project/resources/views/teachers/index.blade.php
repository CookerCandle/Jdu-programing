<x-app-layout>
    <x-slot name="header">
        <h2 class="font-semibold text-xl text-gray-800 leading-tight">
            {{ __('Teachers') }}
        </h2>
    </x-slot>

<div class=" grid grid-cols-1 sm:grid-cols-2 lg:grid-cols-3 gap-6 p-4">
    @foreach($teachers as $teacher)
    <div class="group bg-white rounded-2xl shadow-sm border border-gray-100 hover:shadow-xl hover:-translate-y-1 transition-all duration-300 overflow-hidden">
        
        <div class="h-2 bg-indigo-600"></div>

        <div class="p-6">
            <div class="flex items-center space-x-4 mb-4">
                <div class="flex-shrink-0 w-12 h-12 bg-indigo-100 text-indigo-700 rounded-full flex items-center justify-center font-bold text-lg uppercase">
                    {{ mb_substr($teacher->first_name, 0, 1) }}{{ mb_substr($teacher->last_name, 0, 1) }}
                </div>
                
                <div>
                    <h3 class="text-lg font-bold text-gray-900 group-hover:text-indigo-600 transition-colors">
                        {{ $teacher->first_name }} {{ $teacher->last_name }}
                    </h3>
                    <span class="inline-flex items-center px-2.5 py-0.5 rounded-full text-xs font-medium bg-green-100 text-green-800">
                        Активен
                    </span>
                </div>
            </div>

            <div class="space-y-2 mb-6">
                <div class="flex items-center text-sm text-gray-600">
                    <svg class="w-4 h-4 mr-2 text-gray-400" fill="none" stroke="currentColor" viewBox="0 0 24 24"><path stroke-linecap="round" stroke-linejoin="round" stroke-width="2" d="M3 8l7.89 5.26a2 2 0 002.22 0L21 8M5 19h14a2 2 0 002-2V7a2 2 0 00-2-2H5a2 2 0 00-2 2v10a2 2 0 002 2z"></path></svg>
                    {{ $teacher->email ?? 'no-email@jdu.uz' }}
                </div>
                <div class="flex items-center text-sm text-gray-600">
                    <svg class="w-4 h-4 mr-2 text-gray-400" fill="none" stroke="currentColor" viewBox="0 0 24 24"><path stroke-linecap="round" stroke-linejoin="round" stroke-width="2" d="M8 7V3m8 4V3m-9 8h10M5 21h14a2 2 0 002-2V7a2 2 0 00-2-2H5a2 2 0 00-2 2v10a2 2 0 002 2z"></path></svg>
                    Добавлен: {{ $teacher->created_at->format('d.m.Y') }}
                </div>
            </div>

            <div class="flex items-center justify-between pt-4 border-t border-gray-50">
                <a href="{{ route('teachers.show', $teacher->id) }}" class="text-sm font-semibold text-indigo-600 hover:text-indigo-800 transition-colors">
                    Подробнее →
                </a>
                
                <div class="flex space-x-2">
                    <a href="{{ route('teachers.edit', $teacher->id) }}" class="p-2 text-gray-400 hover:text-blue-600 transition-colors">
                        <svg class="w-5 h-5" fill="none" stroke="currentColor" viewBox="0 0 24 24"><path stroke-linecap="round" stroke-linejoin="round" stroke-width="2" d="M15.232 5.232l3.536 3.536m-2.036-5.036a2.5 2.5 0 113.536 3.536L6.5 21.036H3v-3.572L16.732 3.732z"></path></svg>
                    </a>
                    
                    <form action="{{ route('teachers.destroy', $teacher->id) }}" method="POST" onsubmit="return confirm('Удалить?')">
                        @csrf
                        @method('DELETE')
                        <button type="submit" class="p-2 text-gray-400 hover:text-red-600 transition-colors">
                            <svg class="w-5 h-5" fill="none" stroke="currentColor" viewBox="0 0 24 24"><path stroke-linecap="round" stroke-linejoin="round" stroke-width="2" d="M19 7l-.867 12.142A2 2 0 0116.138 21H7.862a2 2 0 01-1.995-1.858L5 7m5 4v6m4-6v6m1-10V4a1 1 0 00-1-1h-4a1 1 0 00-1 1v3M4 7h16"></path></svg>
                        </button>
                    </form>
                </div>
            </div>
        </div>
    </div>
    @endforeach
    {{ $teachers->links() }}
</div>
</x-app-layout>
