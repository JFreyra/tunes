void init(song_node *arr[], int i){
  while(i){
    arr[i] = (song_node*)malloc(sizeof(song_node));
    arr[i] = NULL;
    i--;
  }
}

song_node *addNewSong(char *name, char *artist, song_node *arr[]){
  return insert_alpha(name,artist,arr[artist[0]-97]);
}

song_node *searchFor(char *name, char *artist, song_node *arr[]){
  return findSong(name,artist,arr[artist[0]-97]);
}

void printListLetter(char *letter, song_node *arr[]){
  print_list(arr[letter[0]-97]);
}

void printListArtist(char *artist, song_node *arr[]){
  print_list(findArtistAll(artist,arr[artist[0]-97]));
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
  deleteNode(name,artist,arr[artist[0]-97]);
}

void deleteAll(song_node *arr[]){
  int i;
  for(i = 0; i < 26; i++)
    free_list(arr[i]);
}
