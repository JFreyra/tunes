#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "songList.h"
#include "songTable.h"



void main(){
  
  srand(time(NULL));

  song_node *table[26];
  init(table,26);
  printf("name of added song: %s - %s\n",addNewSong("testNameA","AtestArt",table)->name,"AtestArt");
  printf("name of added song: %s - %s\n",addNewSong("testNameB","AtestArt",table)->name,"AtestArt");
  printf("name of added song: %s - %s\n",addNewSong("testNameA","BtestArt",table)->name,"BtestArt");
  //print_list(table[0]);
  printLibrary(table);
  printf("\nfinding testNameA: BtestArt\n");
  printf("--> %s\n",searchFor("testNameA","BtestArt",table)->name);

  /* song_node *one = (song_node*)malloc(sizeof(song_node)); */
  /* one = NULL; */
  /* print_list(one); */

  /* printf("%d\n","abc\n"[0]); */
  
}
 
