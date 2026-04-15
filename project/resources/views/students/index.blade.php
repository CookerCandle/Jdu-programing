<x-app-layout>
    <x-slot name="header">
        <div class="flex justify-between items-center">
            <h2 class="font-semibold text-xl text-gray-800 leading-tight">
                {{ __('Students') }}
            </h2>
            <a href="{{ route('students.create') }}" class="bg-blue-500 hover:bg-blue-700 text-white font-bold py-2 px-4 rounded">
                Add Student
            </a>
        </div>
    </x-slot>
    <div class="py-12">
        <div class="max-w-7xl mx-auto sm:px-6 lg:px-8">
            <div class="bg-white overflow-hidden shadow-sm sm:rounded-lg">
                @if(session('success'))
                    <div class="alert alert-success bg-green-100 border border-green-400 text-green-700 px-4 py-3 rounded relative" role="alert">
                        {{ session('success') }}
                    </div>
                @endif
                <div class="p-6 text-gray-900">
                    <div class="grid grid-cols-2 lg:grid-cols-3 gap-4">
                        @foreach($students as $student)
                            <div class="mb-4 p-4 border rounded items-flex flex-col">
                                <h3 class="text-lg font-semibold">{{ $student->firstname }}</h3>
                                <p class="text-gray-600 sm:text-sm">{{ $student->lastname }}</p>
                                <a href="{{ route('students.show', $student->id) }}" class="text-blue-500 hover:text-blue-700">
                                    View Details
                                </a>
                            </div>
                        @endforeach
                    </div>
                    {{ $students->links() }}
                </div>
            </div>
        </div>
    </div>
</x-app-layout>
