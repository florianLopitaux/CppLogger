:: build object files
g++ -c .\src\cpp\DebugLogger.cpp -I.\src\include -o .\bin\DebugLogger.o

:: build library
ar -cqs .\bin\libCppLogger.a .\bin\DebugLogger.o

:: build library test executable
g++ .\src\testLogger.cpp -o .\bin\testLogger.exe -L.\bin\ -lCppLogger -I.\src\include

:: clean object files
del /f ".\bin\*.o"
