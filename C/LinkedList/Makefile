SRC = main.c ll.c
OBJ = main.o ll.o
HDR = ll.h
TRG = ll

${TRG}: ${OBJ}
	gcc ${OBJ} -o ${TRG}

main.o: main.c ${HDR}
	gcc -c main.c -o main.o

ll.o:	ll.c ${HDR}
	gcc -c ll.c -o ll.o

clean:
	rm -f ${OBJ} ${TRG}
	rm -f *~
test:
	./rand.sh 10 100 | ./${TRG}
