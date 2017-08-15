all: prog.elf 

prog.elf: my_prog.o main.o
	g++ -I inc my_prog.o  main.o -o prog.elf

my_prog.o: my_prog.cpp inc/my_vector.h
	g++ -I inc my_prog.cpp -c -o my_prog.o

main.o: main.cpp inc/my_vector.h
	g++ -I inc main.cpp -c -o main.o

clean:
	rm *.o *.elf