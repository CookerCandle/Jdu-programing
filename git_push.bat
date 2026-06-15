@echo off
:: Укажите ниже точный путь к вашей папке с проектом
cd /d "C:\путь\к\вашему\проекту"

chcp 65001 > nul
echo === ЗАПУСК АВТО-КОММИТА ===

:: Проверка наличия Git
where git >nul 2>nul
if %errorlevel% neq 0 (
    echo [ОШИБКА] Git не установлен или не добавлен в PATH!
    goto end
)

:: Проверка, что это Git-репозиторий
if not exist .git (
    echo [ОШИБКА] В папке %cd% нет Git-репозитория .git!
    goto end
)

echo 1. Добавление изменений...
git add .

set /p msg="Введите описание коммита (или нажмите Enter): "
if "%msg%"=="" (
    set msg=Auto-commit %date% %time%
)

echo.
echo 2. Коммит изменений...
git commit -m "%msg%"

echo.
echo 3. Отправка на GitHub...
for /f "tokens=*" %%i in ('git branch --show-current') do set current_branch=%%i

git push origin %current_branch%

if %errorlevel% equ 0 (
    echo [УСПЕХ] Изменения в ветке "%current_branch%" обновлены!
) else (
    echo [ОШИБКА] Ошибка при push.
)

:end
echo.
echo Для выхода нажмите любую кнопку...
pause > nul
