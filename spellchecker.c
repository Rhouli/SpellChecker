/*Ryan Houlihan
 *Lab 6
 *2107
 *spellchecker.c
 *
 *Spell Checks a file using the the standard dictonary if non supplied by the user 
 */

#include "spellchecker.h"

int main(int argc, char *argv[]){
  char **words;
  char *filename;
  char *dictonary;
  int x, fileSize = 0, dicSize = 0, spellCheck;

  Dict* d = (Dict *) malloc(sizeof(Dict));
  if(argc == 2){
    filename = argv[1];
    words = getUserFile(filename, &fileSize);
    if(words == NULL)
      return -1;
    d->words = getUserFile(STANDDIC, &dicSize);
    if(d->words == NULL)
      return -1;
    d->head = d->words[0];
  }
  else if(argc == 3){
    filename = argv[1];
    dictonary = argv[2];
    words = getUserFile(filename, &fileSize);
    if(words == NULL)
      return -1;
    d->words = getUserFile(dictonary, &dicSize);
    if(d->words == NULL)
      return -1;
    d->head = d->words[0];
  }
  else{
    fprintf(stderr,"Incorrect usage. Use ./spellchecker filename dictonaryFile(optional)\n");
    return 0;
  }
  for(x = 0; x < fileSize;x++){
    spellCheck = 0;
    spellCheck = inDict(d, words[x], dicSize);
    if(spellCheck == 1){
      fprintf(stderr,"%15s\t\t\t\tOK\n", words[x]);
    }
    else
      fprintf(stderr, "%15s\t\t\t\tINCORRECT! Suggestion: %s\n", words[x], d->words[spellCheck]);
  }
  free(d);
  free(words);
  return 1;
}

