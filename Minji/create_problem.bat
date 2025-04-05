@echo off
setlocal enabledelayedexpansion

rem Get problem number
if "%~1"=="" (
    echo Enter problem number:
    set /p problem_number=
) else (
    set problem_number=%~1
)

rem Create folder for the problem
mkdir %problem_number%
cd %problem_number%

rem Copy Util.cpp file from common Util folder
set "util_path=..\..\Util\Util.cpp"
copy "%util_path%" "%problem_number%.cpp"
echo Copied Util.cpp to %problem_number%.cpp successfully.

rem Create README.md file
echo # Baekjoon Problem %problem_number% > README.md
echo. >> README.md
echo ## Problem >> README.md
echo [Problem Link](https://www.acmicpc.net/problem/%problem_number%) >> README.md

echo.
echo Problem %problem_number% environment created successfully.
echo Folder: %problem_number%
echo Files: %problem_number%.cpp, README.md

rem Open in VS Code
code %problem_number%.cpp README.md

endlocal