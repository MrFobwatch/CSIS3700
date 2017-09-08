fraction: main.o Fraction.o Point.o
	g++ -o fraction main.o Fraction.o Point.o
	
main.o: main.cpp Point.h
	g++ -c main.cpp
	
Fraction.o: Fraction.cpp Fraction.h
	g++ -c Fraction.cpp
	
Point.o: Point.cpp Point.h
	g++ -c Point.cpp
