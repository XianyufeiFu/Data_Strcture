.PHONY: clean

hello: hello.o
	g++ hello.o -o hello

hello.o: hello.cpp
	g++ -c hello.cpp

clean :
	rm -f *.o
	rm -f hello.exe 