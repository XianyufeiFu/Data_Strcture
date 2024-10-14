.PHONY: clean
-std = c++20

hello: main.o
	g++ main.o -o main

hello.o: main.cpp
	g++ -c main.cpp

clean :
	rm -f *.o
	rm -f main.exe 