all: songList.o songTable.o tunes.o
	gcc songList.o songTable.o tunes.o -o tunes

songList.o: songList.c songList.h
	gcc -c songList.c

songTable.o: songTable.c songTable.h
	gcc -c songTable.c

tunes.o: tunes.c songList.h songTable.h
	gcc -c tunes.c

clean:
	rm *.o
	rm *~

run: all
	./tunes
