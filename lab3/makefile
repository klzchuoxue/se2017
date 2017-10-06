LIBS = -std=gnu++11

main.out: main.o function.o
	g++ -o main.out main.o function.o ${LIBS}
main.o: main.cpp function.h
	g++ -c main.cpp ${LIBS}
function.o: function.cpp function.h
	g++ -c function.cpp ${LIBS}

clean: 
	rm main.out main.o function.o
