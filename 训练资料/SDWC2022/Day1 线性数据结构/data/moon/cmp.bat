:loop
mkdt.exe
moon.exe > std.out
bf.exe > bf.out
fc std.out bf.out
if %errorlevel% ==0 goto loop
pause
