<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>laravel</title>
</head>
<body>
    <nav>
        <ul>
            <li><a href="{{ route('hello') }}">Hello</a></li>
            <li><a href="{{ route('about') }}">About</a></li>
            <li><a href="{{ route('contact') }}">Contact</a></li>
            <li><a href="{{ route('services') }}">Services</a></li>
            <li><a href="{{ route('blog') }}">Blog</a></li>
        </ul>
    </nav>

    <main>
        {{ $slot }}
    </main>
</body>
</html>