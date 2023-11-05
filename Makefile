all: chrenc.c chrenc.h
	gcc -c chrenc.c -std=c89
	ar rcs chrenc.a *.o

clean:
	rm -rf *.o

clear:
	clear
	make all

