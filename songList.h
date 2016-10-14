#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct song_node{
  char name[256];
  char artist[256];
  struct song_node *next;
} song_node;

void print_list(song_node *iter){
  while(iter){
    printf("%d\n",iter->value);
    iter = iter->next;
  }
}

song_node *insert_front(char *newName, char *newArtist, song_node *start){
  song_node *newStart = (song_node*)malloc(sizeof(song_node));
  strcpy(newStart->name,newName);
  strcpy(newStart->artist,newArtist);
  newStart->next = start;
  return newStart;
}

song_node *insert_alpha(char *newName, char *newArtist, song_node *start){
  song_node *newInsert = (song_node*)malloc(sizeof(song_node));
  strcpy(newInsert->name,newName);
  strcpy(newInsert->artist,newArtist);
  while(start->next){
    artist1 = newInsert->artist;
    artist2 = start->next->artist;
    if(strcmp(newInsert->artist,start->next->artist) = 0)
      if(strcmp(newInsert->artist,start->next->artist
  }
  return newInsert;
}

song_node *free_list(song_node *start){
  song_node *startTemp = start;
  while(start){
    song_node *temp = start->next;
    start->next = NULL;
    free(start);
    start = temp;
  }
  return start;
}
