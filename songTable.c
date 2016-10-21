#include "songTable.h"
#include "songList.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void init(song_node *arr[], int i){
  while(i){
    arr[i-1] = (song_node*)malloc(sizeof(song_node));
    arr[i-1] = NULL;
    i--;
  }
}

int toLower(int letter){
  if(letter >= 65 && letter <= 90)
    letter += 32;
  return letter;
}

song_node *addNewSong(char *name, char *artist, song_node *arr[]){
  int letter = toLower((int)(artist[0]));
  if(!arr[letter-97] || strcmp(arr[letter-97]->name,name) > 0){
    arr[letter-97] = insert_alpha(name,artist,arr[letter-97]);
    return arr[letter-97];
  }
  return insert_alpha(name,artist,arr[letter-97]);
}

song_node *searchFor(char *name, char *artist, song_node *arr[]){
  int letter = toLower((int)(artist[0]));
  return findSong(name,artist,arr[letter-97]);
}

void printListLetter(char letter, song_node *arr[]){
  char letterLower = (char)toLower((int)(letter));
  print_list(arr[letterLower-97]);
}

void printListArtist(char *artist, song_node *arr[]){
  int letter = toLower((int)(artist[0]));
  print_list(findArtistAll(artist,arr[letter-97]));
}

void printLibrary(song_node *arr[]){
  int i;
  for(i = 0; i < 26; i++){
    if(arr[i]){
      printf("%c list:\n",i+97);
      print_list(arr[i]);
      printf("\n");
    }
  }
}

// Must take a Library with songs in it
song_node *shuffleList(song_node *arr[], int n){
  song_node *start = (song_node*)malloc(sizeof(song_node));
  start = 0;
  while(n){
    int arrInd = rand() % 26;
    song_node *tempNode = findRand(arr[arrInd]); // attempts to search empty list
    if(!tempNode)
      continue;
    char *nameTemp = tempNode->name;
    char *artTemp = tempNode->artist;
    start = insert_front(nameTemp,artTemp,start);
    n--;
  }
  return start;
}

song_node *deleteSong(char *name, char *artist, song_node *arr[]){
  int letter = toLower((int)(artist[0]));
  if(!strcmp(arr[letter-97]->name,name) && !strcmp(arr[letter-97]->artist,artist)){
    arr[letter-97] = deleteNode(name,artist,arr[letter-97]);
    return arr[letter-97];
  }
  return deleteNode(name,artist,arr[letter-97]);
}

void deleteAll(song_node *arr[]){
  int i;
  for(i = 0; i < 26; i++){
    free_list(arr[i]);
    arr[i] = NULL;
  }
}
