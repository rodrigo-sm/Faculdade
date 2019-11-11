main: main.o cobertura_vacinal.o hashmap.o avl.o
	gcc -o main main.o cobertura_vacinal.o hashmap.o avl.o -W -Wall

cobertura_vacinal.o: cobertura_vacinal.h hashmap.h avl.h dados_cobertura_vacinal.h
	gcc -c cobertura_vacinal.c -W -Wall

hashmap.o: hashmap.h listaord.h dados_cobertura_vacinal.h
	gcc -c hashmap.c -W -Wall

listaord.o: listaord.h cobertura_vacinal.h
	gcc -c listaord.c -W -Wall

avl.o: avl.h dados_cobertura_vacinal.h
	gcc -c avl.c -W -Wall
