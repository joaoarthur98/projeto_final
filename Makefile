all: main

main: methods.o main.c 
	gcc main.c -o main methods.o -W -g

fundo.o: methods.c 
	gcc -c methods.c -W -g 

clean:
	rm -f *.o
