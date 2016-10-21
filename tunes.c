#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "songList.h"
#include "songTable.h"



void main(){
  
  srand(time(NULL));
  
  // INITIALIZATION
  song_node *table[26];
  init(table,26);

  print_list(table[0]);
  printf("\n");
  printLibrary(table);
  printf("\n");
  
  printf("name of added song: %s - %s\n",addNewSong("testNameA","A",table)->name,"A");
  printf("name of added song: %s - %s\n",addNewSong("testNameB","A",table)->name,"A");
  printf("name of added song: %s - %s\n",addNewSong("testNameC","AB",table)->name,"AB");
  printf("name of added song: %s - %s\n",addNewSong("testNameD","AB",table)->name,"AB");
  printf("name of added song: %s - %s\n",addNewSong("testNameA","BtestArt",table)->name,"BtestArt");
  printf("name of added song: %s - %s\n",addNewSong("testNameA","CtestArt",table)->name,"CtestArt");
  printf("name of added song: %s - %s\n",addNewSong("testNameA","DtestArt",table)->name,"DtestArt");
  printf("\n");

  // FIND SONGS
  printf("Testing Find Songs:\n");
  
  printf("\nlooking for 'testNameA' - 'A'\n");
  song_node *temp = searchFor("testNameA","A",table);
  printf("%s - %s\n",temp->name,temp->artist);
  
  printf("\nlooking for 'testNameD' - 'A'\n");
  temp = searchFor("testNameD","A",table);
  // if not found, searchFor returns NULL
  if(temp)
    printf("%s - %s\n",temp->name,temp->artist);
  else
    printf("not found\n");
  
  printf("\nlooking for 'testNameA' - 'CtestArt'\n");
  temp = searchFor("testNameA","CtestArt",table);
  printf("%s - %s\n",temp->name,temp->artist);
  printf("\n");

  // FIND ARTIST
  printf("Testing Find Artist:\n");

  printf("\nlooking for 'A'\n");
  printListArtist("A",table);

  printf("\nlooking for 'CtestArt'\n");
  printListArtist("CtestArt",table);

  // Does not produce output artist does not exist/produces empty output
  printf("\nlooking for 'D'\n");
  printListArtist("D",table);
  printf("Does not produce output artist does not exist/produces empty output\n");
  printf("\n");

  // PRINT LETTER
  printf("Testing Print Letter:\n");

  printf("\na list\n");
  printListLetter('a',table);

  printf("\nd list\n");
  printListLetter('D',table);

  printf("\np list\n");
  printListLetter('p',table);
  printf("Does not produce output artist does not exist/produces empty output\n");
  printf("\n");

  // PRINT LIBRARY
  printf("Testing Print Library:\n\n");

  printLibrary(table);
  printf("\n");

  // REMOVE SONG
  printf("Testing Remove Song:\n");

  printLibrary(table);
  
  printf("\nremove testNameA - A\n");
  deleteSong("testNameA","A",table);
  printLibrary(table);

  printf("\nremove testNameA - CtestArt\n");
  deleteSong("testNameA","CtestArt",table);
  printLibrary(table);

  printf("\nremove testNameD - A\n");
  deleteSong("testNameD","A",table);
  printf("Does not produce output artist does not exist/produces empty output\n");
  printf("\n");

  // ADD
  printf("Testing Add:\n");

  printf("\nadding testNameA - A\n");
  printf("name of added song: %s - %s\n",addNewSong("testNameA","A",table)->name,"A");

  printf("\nadding testNameA - CtestArt\n");
  printf("name of added song: %s - %s\n",addNewSong("testNameA","CtestArt",table)->name,"CtestArt");

  printLibrary(table);

  printf("\n");

  // SHUFFLE
  printf("Testing Shuffle:\n");

  printf("\nshuffle list: 3 songs\n");
  print_list(shuffleList(table,3));
  printf("\n");

  // DELETE ALL
  printf("Testing Delete All:\n\n");

  printf("Before:\n");
  printLibrary(table);
  deleteAll(table);
  printf("After:\n");
  printLibrary(table);
}
 
