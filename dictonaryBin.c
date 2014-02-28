/*Ryan Houlihan
 *Lab 6
 *2107
 *dictonaryBin.c
 *
 *Uses a binary search to see if the given word matches any in the given dictonary
 */
#include "spellchecker.h"

char* stringToLower(char*);

int inDict(Dict* d, char word[], int dicSize){
  int low = 0, high = dicSize, middle = dicSize/2;
  while(low != middle && high != middle){
    if(strcmp(stringToLower(word),stringToLower(d->words[middle]))>0){
      low = middle;
      middle = ((high-low)/2)+low;
    }
    else if(strcmp(stringToLower(word),stringToLower(d->words[middle]))<0){
      high = middle;
      middle = ((high-low)/2)+low;
    }
    else if(strcmp(stringToLower(word),stringToLower(d->words[middle]))==0)
      return 1;
  }

  if(high == middle){
    return low;
  }
  else if(low == middle){
    return high;
  }
  return 0;
}

char* stringToLower(char *word){
    int x = 0;
    for(x = 0; word[x] != 0; x++){
      if(word[x] <= 'Z' && word[x] >= 'A')
	word[x]+=32;
    }
    return word;
  }
