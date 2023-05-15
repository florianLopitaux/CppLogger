@echo off
:: clean old library
IF EXIST ".\lib\libCppLogger.a" del /f ".\lib\libCppLogger.a"

:: build object files
g++ -c .\src\cpp\DebugLogger.cpp -o .\bin\DebugLogger.o -I.\src\include

:: build library
ar -cqs .\lib\libCppLogger.a .\bin\DebugLogger.o

:: clean object files
del /f ".\bin\*.o"

:: build library test program
g++ .\src\testLogger.cpp -o .\bin\testLogger.exe -I.\src\include -L.\lib\ -lCppLogger
