<form action="{{ isset($item) ? route('students.update', $item->id) : route('students.store') }}" method="POST">
    @csrf
    @if(isset($item))
        @method('PUT')
    @endif
    <div class="mb-4">
        <label for="firstname" class="block text-gray-700 text-sm font-bold mb-2">First Name:</label>
        <input type="text" name="firstname" id="firstname" value="{{ isset($item) ? $item->firstname : '' }}" class="shadow appearance-none border rounded w-full py-2 px-3 text-gray-700 leading-tight focus:outline-none focus:shadow-outline">
        <p class="text-red-500 text-xs italic">{{ $errors->first('firstname') }}</p>
    </div>
    <div class="mb-4">
        <label for="lastname" class="block text-gray-700 text-sm font-bold mb-2">Last Name:</label>
        <input type="text" name="lastname" id="lastname" value="{{ isset($item) ? $item->lastname : '' }}" class="shadow appearance-none border rounded w-full py-2 px-3 text-gray-700 leading-tight focus:outline-none focus:shadow-outline">
        <p class="text-red-500 text-xs italic">{{ $errors->first('lastname') }}</p>
    </div>
    <button type="submit" class="bg-blue-500 hover:bg-blue-700 text-white font-bold py-2 px-4 rounded">
        {{ isset($item) ? 'Update' : 'Submit' }}
    </button>
</form>