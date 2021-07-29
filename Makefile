CXX_FLAG = --std=c++11 -g

all: testcards game

testcards: testcards.o cards.o
		g++ $(CXX_FLAG) -o testcards testcards.o cards.o

game: main.o cards.o
		g++ $(CXX_FLAG) -o game main.o cards.o

clean:
	rm -f testcards game *.o
