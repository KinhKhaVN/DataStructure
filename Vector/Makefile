CXX = g++
CXXFLAGS = -g -O2 -Wall -Wextra -std=c++11

SHELL := powershell.exe

all: main.exe

main.exe: main.o
	$(CXX) -o main.exe main.o

main.o: main.cpp Vector.h
	$(CXX) $(CXXFLAGS) -c main.cpp

run:
	main.exe

clean:
	rm *.o, main.exe
