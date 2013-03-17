IF NOT EXIST "%1" mkdir "%1"
copy "%2Debug\JakRandrSolstice.exe" "%1"
copy "%2Debug\SolsticeRuntime.dll" "%1"
copy "%2Debug\SolsticePlugins.dll" "%1"
copy "%3run.bat" "%1"

echo done