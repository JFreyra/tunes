#include "songList.h"

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

// issues with print_list from printLibrary: cannot print empty library
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
  while(start->next){
    char *artist1 = newInsert->artist;
    char *artist2 = start->next->artist;
    char *name1 = newInsert->name;
    char *name2 = start->next->name;
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

song_node *findSong(char *nameTest, char *artTest, song_node *start){
  while(start){
    if(!strcmp(nameTest,start->name) && !strcmp(artTest,start->artist))
      return start;
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

// How do I make random truly random
song_node *findRand(song_node *start){
  int n = rand() % 30;
  printf("random: %d",n);
  song_node *temp = start;
  while(n){
    temp = temp->next;
    printf("\n\n::DIAG:: rand entered\n\n");
    n--;
    if(!temp){
      temp = start;
    }
  }
  return temp;
}

int deleteNode(char *name, char *artist, song_node *start){
  while(start->next){ // while start has a next (which has a next)
    char *nameTest = start->next->name; // name of next of start
    char *artTest = start->next->artist; // artist of next of start
    if(!strcmp(name,nameTest) && !strcmp(artist,artTest)){ // if givens == tests
      song_node *newNext;
      song_node *removed;
      newNext = start->next->next; // temp var to close hole
      removed = start->next; // temp var to return removed value
      start->next->next = NULL; // cutoff node (maybe change to start->next = NULL?)
      free(start->next); // free node
      start->next = newNext; // close hole
      return 1; // return true
    }
    start = start->next; // if not removed, move down the list one node
  }
  return 0; // if not removed, return false
}
