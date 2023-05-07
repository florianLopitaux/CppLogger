all : libCppLogger.a

libCppLogger.a : DebugLogger.o 
	ar -cqs bin/libCppLogger.a bin/DebugLogger.o

DebugLogger.o : src/cpp/DebugLogger.cpp src/include/DebugLogger.h src/include/LoggerColor.h
	g++ -o bin/DebugLogger.o -c src/cpp/DebugLogger -Isrc/include

clean:
	rm bin/*.o bin/*.a
