# Jantar dos filósofos

output: main.o start_sem.o start_threads.o filosofos.o come.o pensa.o 
	gcc -o app -pthread main.c start_sem.c start_threads.c filosofos.c come.c pensa.c 

main.o: main.c 
	gcc -c main.c

start_sem.o: start_sem.c 
	gcc -c start_sem.c

start_threads.o: start_threads.c 
	gcc -c start_threads.c

filosofos.o: filosofos.c 
	gcc -c filosofos.c

come.o: come.c 
	gcc -c come.c

pensa.o: pensa.c 
	gcc -c pensa.c

clean: 
	rm *.o app
