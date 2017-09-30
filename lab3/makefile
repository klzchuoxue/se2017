main.out: main.o function.o
	gcc -o main.out main.o function.o
main.o: main.c function.h
	gcc -c main.c
function.o: function.c function.h
	gcc -c function.c

clean: 
	rm main.out main.o function.o
