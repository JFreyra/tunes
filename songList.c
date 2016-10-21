#include "songList.h"

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void print_list(song_node *iter){
  while(iter){
    printf("%s: %s\n",iter->artist,iter->name);
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
  if(!start){
    return newInsert;
  }
  char *artist1 = newInsert->artist;
  char *artist2 = start->artist;
  char *name1 = newInsert->name;
  char *name2 = start->name;
  if(!strcmp(artist1,artist2) && strcmp(name1,name2) < 0){
    newInsert->next = start;
    return newInsert;
  }
  while(start->next){
    artist1 = newInsert->artist;
    artist2 = start->next->artist;
    name1 = newInsert->name;
    name2 = start->next->name;
    if(strcmp(artist1,artist2) == 0){
      if(strcmp(name1,name2) < 0){
	break;
      }
    }
    if(strcmp(artist1,artist2) < 0){
      break;
    }
    start = start->next;
  }
  newInsert->next = start->next;
  start->next = newInsert;
  return newInsert;
}

// frees all but the first node for some reason?
song_node *free_list(song_node *start){
  while(start){
    printf("deleting %s - %s\n",start->name,start->artist);
    song_node *temp = start->next;
    start->next = NULL;
    start = NULL;
    free(start);
    start = temp;
  }
  return start;
}

song_node *findSong(char *nameTest, char *artTest, song_node *start){
  while(start){
    if(!strcmp(nameTest,start->name) && !strcmp(artTest,start->artist)){
      return start;
    }
    start = start->next;
  }
  return 0;
}

song_node *findArtistFirst(char *search, song_node *start){
  while(start){
    if(strcmp(search,start->name) == 0)
      return start;
    start = start->next;
  }
  return 0;
}

song_node *findArtistAll(char *search, song_node *start){
  song_node *init = (song_node*)malloc(sizeof(song_node));
  init = 0;
  while(start){
    if(strcmp(search,start->artist) == 0){
      if(!init)
	init = insert_alpha(start->name,search,init);
      else
        insert_alpha(start->name,search,init);
    }
    start = start->next;
  }
  return init;
}

song_node *findRand(song_node *start){
  int n = rand() % 30;
  song_node *temp = start;
  while(n && temp){
    temp = temp->next;
    n--;
    if(!temp){
      temp = start;
    }
  }
  return temp;
}

song_node *deleteNode(char *name, char *artist, song_node *start){
  song_node *removedNext;
  if(!strcmp(name,start->name) && !strcmp(artist,start->artist)){
    removedNext = start->next;
    start->next = NULL;
    start = NULL;
    free(start);
    return removedNext;
  }
  while(start->next){ // while start has a next (which has a next)
    char *nameTest = start->next->name; // name of next of start
    char *artTest = start->next->artist; // artist of next of start
    if(!strcmp(name,nameTest) && !strcmp(artist,artTest)){ // if givens == tests
      if(start->next->next){
	removedNext = start->next->next; // temp var to close hole
	start->next->next = NULL; // cutoff node (maybe change to start->next = NULL?)
      }
      free(start->next); // free node
      start->next = removedNext; // close hole
      return removedNext; // return true
    }
    start = start->next; // if not removed, move down the list one node
  }
  return 0; // if not removed, return false
}
