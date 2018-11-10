@echo off
GOTO %1

: -a
	g++ -c src\Matrix.cpp -o obj\Matrix.o
	g++ -c src\main.cpp -o obj\main.o
goto fin

: -m
	g++ -c src\main.cpp -o obj\main.o
goto fin

: -x
	g++ -c src\Matrix.cpp -o obj\Matrix.o
goto fin

: -b
	g++ -o bin\main.exe obj\Matrix.o obj\main.o
goto fin

: -r
bin\main.exe

:fin
:: -a compile all
:: -m compile main
:: -x compile matrix
:: -b build
:: -r rnu
