#ifndef SONGLISTH

#define SONGLISTH

typedef struct song_node{
  char name[256];
  char artist[256];
  struct song_node *next;
} song_node;

void print_list(song_node *iter)
song_node *insert_front(char *newName, char *newArtist, song_node *start)
song_node *insert_alpha(char *newName, char *newArtist, song_node *start)
song_node *free_list(song_node *start)
song_node *findSong(char *nameTest, char *artTest, song_node *start)
song_node *findArtistFirst(char *search, song_node *start)
song_node *findArtistAll(char *search, song_node *start)
song_node *findRand(song_node *start)
int deleteNode(char *name, char *artist, song_node *start)

#endif
