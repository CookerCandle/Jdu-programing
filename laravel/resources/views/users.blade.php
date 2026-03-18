<x-layouts.base>
    <h1 class="text-2xl font-bold">Users</h1>
    <ul class="container mx-auto mt-4 flex flex-wrap gap-4 ">
        @foreach ($users as $user)
            <a href="{{ route('user', $user['id']) }}">
                <li class="bg-gray-200 p-2 mb-2  pointer-events-auto">{{ $user['name'] }}</li>
            </a>
        @endforeach
    </ul>
</x-layouts.base>