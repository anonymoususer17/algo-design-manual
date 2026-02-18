@echo off
gcc chapter1.c utilities.c -o chapter1
if %errorlevel% equ 0 (
    chapter1.exe
) else (
    echo Compilation failed
    exit /b 1
)
