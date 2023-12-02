
@echo off
rem Archivo de compilacion de proyecto, se utiliza.bat para evitar el uso
rem de make o cmake

rem Archivos a compilacion
set SOURCE_FILES=main.cpp dataprst.cpp ui.cpp ATM.cpp
rem ejecutable
set OUTPUT_FILE=ATM.exe

rem nos dirigimos al directorio donde esta el soruce file
cd src
echo.
echo  - Archivos a compilar: %SOURCE_FILES%
echo  - Compilando el proyecto . . .

rem Compilamos con g++ y ubicamos el ejecutableen el directorio de arriba, build
g++ %SOURCE_FILES% -o ..\build\%OUTPUT_FILE%

echo.
rem Podemos ejecutar o no el programa
set /p OPT=¿Desea ejecutar el programa? (Y/N): 

rem Aseguramos que n == N, y == Y
set "OPT=%OPT:~0,1%"
set "OPT=%OPT:~0,1%"
if /i "%OPT%"=="y" (
    echo.
    echo  - Ejecutando el programa...
    timeout /t 1 /nobreak >nul
    echo.
    rem nos dirigimos al drectorio de arriba build (donde esta guardado el .exe)
    cd ..\build\
    rem limpiamos pnatalla y ejecutamos
    cls
    ATM.exe
    color 7
) else (
    cd ..
    echo Programa no ejecutado.
    color 7
)

