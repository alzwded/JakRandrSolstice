IF NOT EXIST "%1" mkdir "%1"

echo Copying "%2Debug\SolsticePlugins.dll"
copy "%2Debug\SolsticePlugins.dll" "%1"
IF ERRORLEVEL 1 GOTO :fail

echo Copying "%2Debug\JakRandrSolstice.exe"
copy "%2Debug\JakRandrSolstice.exe" "%1"
IF ERRORLEVEL 1 GOTO :fail

echo Copying "%2Debug\SolsticeRuntime.dll"
copy "%2Debug\SolsticeRuntime.dll" "%1"
IF ERRORLEVEL 1 GOTO :fail

echo Copying "%3run.bat"
copy "%3run.bat" "%1"
IF ERRORLEVEL 1 GOTO :fail

echo done.
EXIT 0

:fail
echo Some of the files were missing
EXIT 1