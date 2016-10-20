#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "songList.h"
#include "songTable.h"



void main(){
  
  song_node *table[26];
  init(table,26);
  printf("name of added song: %s == testNameA\n",addNewSong("testNameA","AtestArt",table)->name);
  printf("name of added song: %s == testName\n",addNewSong("testNameB","AtestArt",table)->name);
  printf("name of added song: %s == testNameA\n",addNewSong("testNameA","BtestArt",table)->name);
  //print_list(table[0]);
  printLibrary(table);

  /* song_node *one = (song_node*)malloc(sizeof(song_node)); */
  /* one = NULL; */
  /* print_list(one); */

  /* printf("%d\n","abc\n"[0]); */
  
}
 
