// search: takes name and artist

// removal of song_node in song_node list
// interacts with the next of start and start
song_node *removeSpecific(char *name, char *artist, song_node *start){
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
      return removed; // return removed node
    }
    start = start->next; // if not removed, move down the list one node
  }
  return 0; // if not removed, return NULL
}

// Array Stuff

song_node *addNewSong(char *name, char *artist, song_node *arr){
  return insert_node(name,artist,arr[artist[0]-97]);
}

song_node *searchFor(char *name, char *artist, song_node *arr){
  return searchForNode(name,artist,arr[artist[0]-97]);
}

void printListLetter(char *letter){
  print_list(arr[letter[0]-97]);
}

void printListArtist(char *artist){
  print_list(searchArtistFull(arr[artist[0]-97]));
}

void printLibrary(song_node *arr){
  int i;
  for(i = 0; i < 26; i++)
    print_list(arr[i]);
}

song_node *shuffleList(song_node *arr, int n){
  song_node *start = (song_node*)malloc(sizeof(song_node));
  start = 0;
  while(n){
    int arrInd = <randomly generated number % 26>;
    song_node *tempNode = randomNode(arr[arrInd]);
    char *nameTemp = tempNode->name;
    char *artTemp = tempNode->artist;
    start = insert_nodeFront(nameTemp,artTemp,start);
    n--;
  }
  return start;
}

song_node *deleteSong(char *name, char *artist, song_node *arr){
  return removeSpecific(name,artist,arr[artist[0]-97]);
}

void deleteAll(song_node *arr){
  int i;
  for(i = 0; i < 26; i++)
    free_list(arr[i]);
}
