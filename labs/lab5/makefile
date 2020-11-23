CC=g++
EXE_FILE=prog

all: $(EXE_FILE)

$(EXE_FILE):  circle.o rectangle.o shape.o square.o application.cpp
	$(CC)  circle.o rectangle.o shape.o square.o application.cpp -o $(EXE_FILE)

circle.o: circle.h circle.cpp
	$(CC) -c circle.cpp

rectangle.o: rectangle.h rectangle.cpp
	$(CC) -c rectangle.cpp

shape.o: shape.h shape.cpp
	$(CC) -c shape.cpp

square.o: square.h square.cpp
	$(CC) -c square.cpp

clean:
	rm -f *.o $(EXE_FILE)
