#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "songList.h"
#include "songTable.h"



void main(){
  
  srand(time(NULL));

  song_node *table[26];
  init(table,26);
  printf("name of added song: %s - %s\n",addNewSong("testNameA","A",table)->name,"A");
  printf("name of added song: %s - %s\n",addNewSong("testNameB","A",table)->name,"A");
  printf("name of added song: %s - %s\n",addNewSong("testNameC","AB",table)->name,"AB");
  printf("name of added song: %s - %s\n",addNewSong("testNameD","AB",table)->name,"AB");
  printf("name of added song: %s - %s\n",addNewSong("testNameA","BtestArt",table)->name,"BtestArt");
  printf("\n");
  printLibrary(table);
  printf("\nprinting shuffleList\n");
  print_list(shuffleList(table,2));

  /* song_node *one = (song_node*)malloc(sizeof(song_node)); */
  /* one = NULL; */
  /* print_list(one); */

  /* printf("%d\n","abc\n"[0]); */
  
}
 
