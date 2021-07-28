CXX_FLAG = --std=c++11 -g

all: testcards

common = cards.o

testcards: testcards.o $(common)
	g++ $(CXX_FLAG) -o testcards



clean:
	rm -f testcards *.o