main: main.o redeSocial.o listaord.o avl.o
	gcc -o main main.o redeSocial.o listaord.o avl.o -W -Wall

redeSocial.o: redeSocial.h listaord.h avl.h
	gcc -c redeSocial.c -W -Wall

listaord.o: listaord.h
	gcc -c listaord.c -W -Wall

avl.o: avl.h listaord.h
	gcc -c avl.c -W -Wall
