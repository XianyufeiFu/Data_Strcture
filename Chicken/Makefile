.PHONY: clean

Chicken: Chicken.o
	g++ Chicken.o -o Chicken

Chicken.o: Chicken.cpp
	g++ -c Chicken.cpp

clean :
	rm -f *.o
	rm -f Chicken.exe 