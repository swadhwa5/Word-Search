// word_search.c
// <STUDENT: Shreya Wadhwa, swadhwa5>
//
//


#include <stdio.h>
#include "search_functions.h"
#include <string.h>
#include <assert.h>

/*
 * This is the HW3 main function that performs a word search.
 */
int main(int argc, char* argv[]) {
  
  FILE* write_to=stdout;
  
  char word[MAX_SIZE];
  char grid[MAX_SIZE][MAX_SIZE];
  if(argc<2) {
    printf("Please enter a command line argument.");
  }
  else {
    
    int n=populate_grid(grid, argv[1]);
    
    if (n !=-2 && n!= -1) {
    
    while((scanf("%s", word))==1) {
     
      to_lower(word);
	find_all  (grid, n, word, write_to);
	// Fill in your main code here!
    }
    }
  }
  fclose(write_to);
  return 0;

}


  
