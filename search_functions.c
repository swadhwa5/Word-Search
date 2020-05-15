// search_functions.c
// <STUDENT: Shreya Wadhwa, swadhwa5>
//
//


#include <stdio.h>
#include "search_functions.h"
#include <string.h>
#include <ctype.h>


/* 
 * Given a filename and a MAX_SIZExMAX_SIZE grid to fill, this function 
 * populates the grid and returns n, the actual grid dimension. 
 * If filename_to_read_from can't be opened, this function returns -1.
 * If the file contains an invalid grid, this function returns -2.
 */
int populate_grid(char grid[][MAX_SIZE], char filename_to_read_from[]){

FILE* input = fopen(filename_to_read_from, "r");
 if (input == NULL) {
printf("Grid file failed to open.");
return -1; // indicate error
 }
 
 int temp=0;
 int i=0;
 char next;
 
while(!feof(input)){
  int j=0;
  // read character                                                                                                                     
    int c = fgetc(input);
    if (c == EOF) {
      // end of file                                                                                                                      
    } else {
      // valid character                                                                                                                  
      next = c;
    }
  while(next!='\n' && next !=' ') {
    grid[i][j]=next;
    
    

    // read character
    c = fgetc(input);
    if (c == EOF) {
      break;      // end of file
    } else {
      // valid character
      next = c;
    }
    j++;
  }
  if(c == EOF) {
    break;
  }
  if (i == 0) {
    temp = j;
    i++;
  }
  else {
    if(j == temp) {
      temp = j;
      i++;
    }
    else {
      printf("Invalid grid.");
      return -2;
    }
  }
  
  
  
  if(j>MAX_SIZE) {
    printf("Invalid grid.");
   return -2;
  }
 }
 
 if (i>10) {
   printf("Invalid grid.");
   return -2;
 }
 
 if(i != temp) {
   printf("Invalid grid.");
   return -2;
 }
 if(i==0 || temp==0) {
   printf("Invalid grid.");
   return -2;
 }

 else {
   int n=i;
   return n;
 }
   
  fclose(input); 

}


/* 
 * find_right 
 */
int find_right(char grid[][MAX_SIZE], int n, char word[], FILE *write_to){

  
  int countr=0;
  
  
  for(int i=0;i<n;i++) {
    for (int j=0;j<n;j++) {
      if(grid[i][j]==word[0]) {
	
	int a=0;
	char maybe_match[MAX_SIZE];
	for(int z=j;z<(j+(int)strlen(word));z++, a++) {
	  maybe_match[a]=grid[i][z];
	  
          
	}
	maybe_match[a]='\0';
	
	to_lower(maybe_match);
	if (strcmp(maybe_match, word)==0) {
	  countr++;
	
	fprintf(write_to,"%s %d %d R\n",word,i,j);
	}
      }
    }
  }
  			       
  return countr;

}


/* 
 * find_left 
 */
int find_left (char grid[][MAX_SIZE], int n, char word[], FILE *write_to){

  int countl=0;
 
  char word_copy[MAX_SIZE];
  strcpy(word_copy,word);
  reverse(word_copy);

  for(int i=0;i<n;i++) {
    for (int j=0;j<n;j++) {
      if(grid[i][j]==word_copy[0]) {

        int a=0;
        char maybe_match[MAX_SIZE];
	int cols=j;
	for(int z=j;z<(j+(int)strlen(word));z++, a++) {
          maybe_match[a]=grid[i][z];
          
	  cols++;
	}
        maybe_match[a]='\0';
	
	to_lower(maybe_match);
        
        if (strcmp(maybe_match, word_copy)==0) {
          countl++;
	  
	  
	  fprintf(write_to,"%s %d %d L\n",word,i,(cols-1));
	}
	
      }
    }
  }

  return countl;

}


/* 
 * find_down 
 */
int find_down (char grid[][MAX_SIZE], int n, char word[], FILE *write_to){

  
  int countd=0;
  

  for(int i=0;i<n;i++) {
    for (int j=0;j<n;j++) {
      if(grid[i][j]==word[0]) {

        int a=0;
        char maybe_match[MAX_SIZE];
        for(int z=i;z<(i+(int)strlen(word));z++, a++) {
          maybe_match[a]=grid[z][j];
          
        }
        maybe_match[a]='\0';
        
	to_lower(maybe_match);
	
        if (strcmp(maybe_match, word)==0) {
          countd++;
        
	fprintf(write_to,"%s %d %d D\n",word,i,j);
 
	}
      }
    }
  }

  return countd;                                                                                                                                                                        

}


/* 
 * find_up 
 */
int find_up   (char grid[][MAX_SIZE], int n, char word[], FILE *write_to){

  int countu=0;
  
  char word_copy[MAX_SIZE];
  strcpy(word_copy,word);
  reverse(word_copy);
  
  for(int i=0;i<n;i++) {
    for (int j=0;j<n;j++) {
      if(grid[i][j]==word_copy[0]) {

	int a=0;
        char  maybe_match[MAX_SIZE];
        
	int rows=i;
	for(int z=i;z<(i+(int)strlen(word));z++, a++) {
          maybe_match[a]=grid[z][j];
          
	  rows++;
        }
        maybe_match[a]='\0';
        
	to_lower(maybe_match);
	
        if (strcmp(maybe_match, word_copy)==0) {
          countu++;
	  
	  
	  fprintf(write_to,"%s %d %d U\n",word,(rows-1),j);
	}
       
      }
    }
  }

  return countu;   

 

}


/* 
 * find_all 
 */
int find_all(char grid[][MAX_SIZE], int n, char word[], FILE *write_to) {
  int e=find_right(grid, n, word, write_to);
  int b=find_left(grid, n, word, write_to);
  int c=find_down(grid, n, word, write_to);
  int d=find_up(grid, n, word, write_to);
  int final=e+b+c+d;
  if (final==0) {
    
    fprintf(write_to,"%s - Not Found\n",word);
  }
  return 0; 

} 


/*
 * Reads lhs and rhs character by character until either reaches eof.
 * Returns true if the files can be read and the two files match
 * character by character. Returns false if two files either can't be
 * opened or don't match. The definition of this function is provided 
 * for you.
 */
int file_eq(char lhs_name[], char rhs_name[]) {
  FILE* lhs = fopen(lhs_name, "r");
  FILE* rhs = fopen(rhs_name, "r");

  // don't compare if we can't open the files
  if (lhs == NULL || rhs == NULL) return 0;

  int match = 1;
  // read until both of the files are done or there is a mismatch
  while (!feof(lhs) || !feof(rhs)) {
	if (feof(lhs) ||                      // lhs done first
		feof(rhs) ||                  // rhs done first
		(fgetc(lhs) != fgetc(rhs))) { // chars don't match
	  match = 0;
	  break;
	}
  }
  fclose(lhs);
  fclose(rhs);
  return match;
}

void  to_lower( char wordl[]) {
  int i=0;
  while(wordl[i]!='\0') {
    wordl[i]=tolower(wordl[i]);
    i++;
  }
  
}

void reverse(char wordr[]) {
  for (int i=0;i<(int)((strlen(wordr))/2);i++) {
    char temp=wordr[i];
    wordr[i]=wordr[((int)(strlen(wordr)))-i-1];
    wordr[((int)(strlen(wordr)))-i-1]=temp;
  }
}
