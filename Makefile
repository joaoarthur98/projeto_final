all: main

main: methods.o main.c 
	gcc main.c -o main methods.o -W -g -lm

fundo.o: methods.c 
	gcc -c methods.c -W -g -lm

clean:
	rm -f *.o
