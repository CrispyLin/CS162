CC=g++
EXE_FILE=prog

all: $(EXE_FILE)

$(EXE_FILE): Card.cpp Card.o Deck.o Deck.cpp Game.o Game.cpp Hand.o Hand.cpp Player.o Player.cpp driver.cpp
	$(CC) Card.o Deck.o Game.o Hand.o Player.o driver.cpp -o $(EXE_FILE)

Card.o: Card.h Card.cpp
	$(CC) -c Card.cpp

Deck.o: Deck.h Deck.cpp
	$(CC) -c Deck.cpp

Game.o: Game.h Game.cpp
	$(CC) -c Game.cpp

Hand.o: Hand.h Hand.cpp
	$(CC) -c Hand.cpp

Player.o: Player.h Player.cpp
	$(CC) -c Player.cpp

clean:
	rm -f *.o $(EXE_FILE)