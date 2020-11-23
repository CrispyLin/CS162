CC=g++
exe_file = catalog_prog 


$(exe_file): catalog.o run_wizard.cpp catalog.h
	$(CC) catalog.o run_wizard.cpp -o $(exe_file)

catalog.o: catalog.cpp catalog.h
	$(CC) -c catalog.cpp

clean: 
	rm -f *.o $(exe_file)