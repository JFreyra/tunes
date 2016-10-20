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
  if(!arr[letter-97]){
    arr[letter-97] = insert_alpha(name,artist,arr[letter-97]);
    return arr[letter-97];
  }
  return insert_alpha(name,artist,arr[letter-97]);
}

song_node *searchFor(char *name, char *artist, song_node *arr[]){
  int letter = toLower((int)(artist[0]));
  return findSong(name,artist,arr[letter-97]);
}

void printListLetter(char *letter, song_node *arr[]){
  int letterInt = toLower((int)(letter[0]));
  print_list(arr[letterInt-97]);
}

void printListArtist(char *artist, song_node *arr[]){
  int letter = toLower((int)(artist[0]));
  print_list(findArtistAll(artist,arr[letter-97]));
}

void printLibrary(song_node *arr[]){
  int i;
  for(i = 0; i < 26; i++){
    if(arr[i])
      print_list(arr[i]);
  }
}

song_node *shuffleList(song_node *arr[], int n){
  song_node *start = (song_node*)malloc(sizeof(song_node));
  start = 0;
  while(n){
    int arrInd = rand() % 26;
    song_node *tempNode = findRand(arr[arrInd]);
    char *nameTemp = tempNode->name;
    char *artTemp = tempNode->artist;
    start = insert_front(nameTemp,artTemp,start);
    n--;
  }
  return start;
}

void deleteSong(char *name, char *artist, song_node *arr[]){
  int letter = toLower((int)(artist[0]));
  deleteNode(name,artist,arr[letter-97]);
}

void deleteAll(song_node *arr[]){
  int i;
  for(i = 0; i < 26; i++)
    free_list(arr[i]);
}
