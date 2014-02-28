/*Ryan Houlihan
 *Lab 6
 *2107
 *dictonaryBin.c
 *
 *Header file
 */

#ifndef __SPELLCHECKER_H__
#define __SPELLCHECKER_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define STANDDIC "standardDictonary.txt" 
#define TRUE 1
#define FALSE 0
#define MAXX 1000000
#define MAXY 50

typedef struct {
  char** words;
  char * head;
} Dict;

char** getUserFile(char* filename, int* size);
int inDict(Dict *d, char *word, int dicSize);

#endif
