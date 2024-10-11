gcc -c --std=c17 -lconio -o main.o main.c
gcc -c --std=c17 -lconio -o temp_functions.o temp_functions.c
gcc -o func_temp.exe main.o temp_functions.o
pause
func_temp.exe -h
pause