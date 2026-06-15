@echo off
setlocal enabledelayedexpansion

:: Автоматически переходим в директорию, откуда запущен этот .bat файл
cd /d "%~dp0"

chcp 65001 > nul
echo === СИНХРОНИЗАЦИЯ С GITHUB ===

:: 1. Проверки окружения
where git >nul 2>nul
if !errorlevel! neq 0 (
    echo [ОШИБКА] Git не найден в PATH!
    goto end
)
if not exist .git (
    echo [ОШИБКА] Тут нет Git-репозитория! Убедитесь, что скрипт лежит в корне проекта.
    goto end
)

:: Получаем имя текущей ветки
for /f "tokens=*" %%i in ('git branch --show-current') do set "branch=%%i"

if "!branch!"=="" (
    echo [ОШИБКА] Не удалось определить текущую ветку.
    goto end
)

echo Текущая ветка: !branch!
echo Рабочая папка: %~dp0
echo.

:: 2. Проверка изменений на сервере
echo [1/4] Проверка изменений на GitHub (git fetch)...
git fetch origin !branch! >nul 2>&1

:: Сбрасываем переменные перед проверкой
set "LOCAL="
set "REMOTE="

:: Сравниваем локальную ветку с удаленной (подавляем ошибки, если ветки еще нет на сервере)
for /f "tokens=*" %%i in ('git rev-parse HEAD 2^>nul') do set "LOCAL=%%i"
for /f "tokens=*" %%i in ('git rev-parse origin/!branch! 2^>nul') do set "REMOTE=%%i"

if "!LOCAL!"=="!REMOTE!" (
    echo На GitHub нет новых изменений. Всё синхронизировано.
) else if "!REMOTE!"=="" (
    echo [ИНФО] Удаленная ветка origin/!branch! пока не существует. Будет создана.
) else (
    echo [ОБНОВЛЕНИЕ] На сервере есть новые коммиты!
    echo [2/4] Скачивание обновлений ^(git pull^)...
    git pull origin !branch!
    
    :: Проверка на конфликты при пулле
    if !errorlevel! neq 0 (
        echo.
        echo [ВНИМАНИЕ] Возникли конфликты при слиянии файлов.
        echo Пожалуйста, разрешите конфликты вручную в вашем редакторе кода.
        goto end
    )
)

echo.
:: 3. Добавление и коммит локальных изменений
echo [3/4] Подготовка ваших изменений...
git add .

:: Надежная проверка наличия изменений (работает даже в пустом репозитории)
git status --porcelain | findstr . >nul
if !errorlevel! neq 0 (
    echo Нет новых локальных изменений для коммита.
    goto do_push
)

:do_commit
set "msg="
set /p msg="Введите описание коммита (или Enter для авто-сообщения): "

:: Безопасное формирование авто-сообщения
if not defined msg (
    :: Убираем возможный пробел перед часами (например, " 9" превращается в "09")
    set "t=!time: =0!"
    for /f "tokens=1-3 delims=:." %%a in ("!t!") do (
        set "msg=Auto-commit %date% %%a-%%b"
    )
)

:: Удаляем кавычки из пользовательского ввода, чтобы не сломать синтаксис команды git commit
set "msg=!msg:"=!"

git commit -m "!msg!"

:do_push
echo.
:: 4. Отправка на GitHub
echo [4/4] Отправка изменений на GitHub (git push)...
git push origin !branch!

if !errorlevel! equ 0 (
    echo.
    echo [УСПЕХ] Все изменения успешно синхронизированы!
) else (
    echo.
    echo [ОШИБКА] Не удалось отправить код на GitHub.
)

:end
echo.
echo Нажмите любую клавишу для выхода...
pause > nul