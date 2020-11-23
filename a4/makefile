CC=g++
EXE_FILE=prog

all: $(EXE_FILE)

$(EXE_FILE): linked_list.o test_linked_list.cpp
	$(CC) linked_list.o test_linked_list.cpp -o $(EXE_FILE)

linked_list.o: linked_list.h node.h linked_list.cpp
	$(CC) -c linked_list.cpp



clean:
	rm -f *.o $(EXE_FILE)