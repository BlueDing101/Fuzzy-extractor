CXX=g++
all: main

func.o: func.cpp func.h
	$(CXX) -c func.cpp
main.o: main.cpp func.h
	$(CXX) -c main.cpp
main: func.o main.o func.h
	$(CXX) func.o main.o -o main `pkg-config opencv --cflags --libs`

clean:
	rm main func.o main.o