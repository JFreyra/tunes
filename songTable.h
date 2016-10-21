#ifndef SONGTABLEH

#define SONGTABLEH

#include "songList.h"

void init(song_node *arr[], int i);
song_node *addNewSong(char *name, char *artist, song_node *arr[]);
song_node *searchFor(char *name, char *artist, song_node *arr[]);
void printListLetter(char letter, song_node *arr[]);
void printListArtist(char *artist, song_node *arr[]);
void printLibrary(song_node *arr[]);
song_node *shuffleList(song_node *arr[], int n);
song_node *deleteSong(char *name, char *artist, song_node *arr[]);
void deleteAll(song_node *arr[]);

#endif
