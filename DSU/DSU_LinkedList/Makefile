CXX = g++
CXXFLAGS = -g -O2 -Wall -Wextra -std=c++11

SHELL := powershell.exe


all: main.exe main.o DSU.o

main.exe: main.o DSU.o
	$(CXX) -o main.exe main.o DSU.o

main.o: main.cpp DSU.h
	$(CXX) $(CXXFLAGS) -c main.cpp

DSU.o: DSU.cpp DSU.h
	$(CXX) $(CXXFLAGS) -c DSU.cpp

run:
	main.exe

clean:
	rm *.o, main.exe

