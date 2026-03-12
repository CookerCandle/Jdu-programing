<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>laravel</title>
    @vite('resources/css/app.css')
</head>
<body>
    <header>
        <x-navbar></x-navbar>
    <header>

    <main>
        {{ $slot }}
    </main>
</body>
</html>