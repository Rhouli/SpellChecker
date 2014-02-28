/*Ryan Houlihan
 *Lab 6
 *2107
 *getFile.c
 *
 *Stores all the words from the given file in a pointer to a pointer
 */

#include "spellchecker.h"
#include <errno.h>

int punctuationFind(char);
extern int errno;

char** getUserFile(char* filename, int *size){
  int INWORD = TRUE, OUTWORD = FALSE, x, y;
  char c, **word;
  char temp[MAXY];
  word = (char**)malloc(sizeof(char*)*MAXX);
  for(x = 0; x < MAXX; x++){
    word[x] = (char*)malloc(sizeof(char)*MAXY);
  }
  FILE *fp;
  if((fp = fopen(filename, "r")) == NULL){
    fprintf(stderr, "Error opening file: %s", strerror(errno));
  }
  for(x = 0, y= 0; (c = getc(fp)) != EOF;){
    if((punctuationFind(c) || isspace(c) || isdigit(c)) && (INWORD == TRUE)){
	INWORD = FALSE;
	OUTWORD = TRUE;
	if(y != 0){
	  word[x] = strcpy(word[x], temp);
	  x++;
	}
	if(x == MAXX){
	  fprintf(stderr, "Bail out, out pointer array is over run!");
	  fclose(fp);
	  return NULL;
	}
      }
      else if(isalpha(c) && OUTWORD){
	OUTWORD = FALSE;
	INWORD = TRUE;
	y = 0;
      }
    if(INWORD){
      temp[y] = c;
      y++;
      temp[y] = '\0';
      if(y == MAXY){
	printf("Bail out, our pointer array is over run!");
	fclose(fp);
	return NULL;
      }
    }
  }
  fclose(fp);
  if(&size != NULL){
    *size = x;
  }
  return (word);
}

/* Checks to see if any punctuation ends the word */
int punctuationFind(char p){
  if(p == '.' || p == ',' || p == ':' || p == '"'|| p == '?')
    return 1;
  return 0;
}
