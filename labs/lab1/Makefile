CC=g++
EXE_FILE=multdiv_run

all: $(EXE_FILE)

$(EXE_FILE): multdiv.o multdiv.h prog.cpp
	$(CC) multdiv.o prog.cpp -o $(EXE_FILE)

multdiv.o: multdiv.h multdiv.cpp
	$(CC) -c multdiv.cpp

clean:
	rm -f *.o $(EXE_FILE)