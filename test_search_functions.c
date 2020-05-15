// test_search_functions.c
// <STUDENT: ADD YOUR INFO HERE: Shreya Wadhwa, swadhwa5>



#include <stdio.h>
#include <assert.h>
#include "search_functions.h"
#include <string.h>

/* 
 * Declarations for tester functions whose definitions appear below.
 * (You will need to fill in the function definition details, at the
 * end of this file, and add comments to each one.) 
 * Additionally, for each helper function you elect to add to the 
 * provided search_functions.h, you will need to supply a corresponding
 * tester function in this file.  Add a declaration for it here, its
 * definition below, and a call to it where indicated in main.
 */
void test_file_eq();      // This one is already fully defined below.
void test_populate_grid();
void test_find_right();
void test_find_left();
void test_find_down();
void test_find_up();
void test_find_all();
void test_to_lower();
void test_reverse();
/*
 * Main method which calls all test functions.
 */
int main() {
  
  
  printf("Testing file_eq...\n");
  test_file_eq();
  printf("Passed file_eq test.\n\n");

  printf("Running search_functions tests...\n");
  
  test_populate_grid();
 
  test_find_right();
  
  test_find_left();
  
  test_find_down();
  
  test_find_up();
  
  test_find_all();
  
  test_to_lower();
  
  test_reverse();
  
  assert(file_eq("correct.txt", "write_to_test.txt"));
  
  printf("Passed search_functions tests!!!\n");

  
  return 0;
}



/*
 * Test file_eq on same file, files with same contents, files with
 * different contents and a file that doesn't exist.
 * Relies on files test1.txt, test2.txt, test3.txt being present.
 */
void test_file_eq() {
  
  FILE* fptr = fopen("test1.txt", "w");
  fprintf(fptr, "this\nis\na test\n");
  fclose(fptr);

  fptr = fopen("test2.txt", "w");
  fprintf(fptr, "this\nis\na different test\n");
  fclose(fptr);

  fptr = fopen("test3.txt", "w");
  fprintf(fptr, "this\nis\na test\n");
  fclose(fptr);

  assert( file_eq("test1.txt", "test1.txt"));
  assert( file_eq("test2.txt", "test2.txt"));
  assert(!file_eq("test2.txt", "test1.txt"));
  assert(!file_eq("test1.txt", "test2.txt"));
  assert( file_eq("test3.txt", "test3.txt"));
  assert( file_eq("test1.txt", "test3.txt"));
  assert( file_eq("test3.txt", "test1.txt"));
  assert(!file_eq("test2.txt", "test3.txt"));
  assert(!file_eq("test3.txt", "test2.txt"));
  assert(!file_eq("", ""));  // can't open file
}


/*
  tests populate_grid by checking values of rows, cols and a temporary variable temp all of which are used to either take input for the no of rows of columns in the grid or to check the invalidity of the grid
 */
void test_populate_grid(){
  char grid[MAX_SIZE][MAX_SIZE];
  
  int pg=populate_grid(grid, "grid.txt");
  
  assert(!(pg==-2));

  char grid_one[MAX_SIZE][MAX_SIZE];
  int pg1=populate_grid(grid_one, "test1.txt");
  assert(pg1 == -2);
    

}

/*
 tests find_right() by comparing correct.txt and write_to_test.txt which have the correct and the generated output respectively 
 */
void test_find_right(){
  char grid[MAX_SIZE][MAX_SIZE];
  populate_grid(grid, "grid.txt");
  char wordtotest[]="key";
  FILE* correct=fopen("correct.txt", "w");
  fprintf(correct,"key 2 1 R\n");
  
  FILE* write_to_test=fopen("write_to_test.txt","w");
    find_right(grid, 4, wordtotest, write_to_test);
 
  
  assert( file_eq("correct.txt","write_to_test.txt"));  
 fclose(correct);
    fclose(write_to_test);
}
  


/* tests find_left() by comparing correct.txt and write_to_test.txt which have the correct and the generated output respectively
 */
void test_find_left(){
char grid[MAX_SIZE][MAX_SIZE];
 populate_grid(grid, "grid.txt");
 char wordtotest[]="tip";
 FILE* correct=fopen("correct.txt", "w");
 fprintf(correct, "tip 0 2 L\n");
 FILE* write_to_test=fopen("write_to_test.txt","w");
    find_left(grid, 4, wordtotest, write_to_test);
   
  
  assert( file_eq("correct.txt","write_to_test.txt"));  
fclose(correct);
    fclose(write_to_test);

}

/* tests find_down() by comparing correct.txt and write_to.txt which have the correct and the generated
 output respectively
 */
void test_find_down(){
char grid[MAX_SIZE][MAX_SIZE];
 populate_grid(grid, "grid.txt");
 char wordtotest[]="pop";
 FILE* correct=fopen("correct.txt", "w");
  fprintf(correct, "pop 0 0 D\n");
  FILE* write_to_test=fopen("write_to_test.txt","w");
  find_down(grid, 4, wordtotest, write_to_test);
  
  
  assert( file_eq("correct.txt","write_to_test.txt"));
fclose(correct);
    fclose(write_to_test);
}

/* tests find_up() by comparing correct.txt and write_to_test.txt which have the correct and the generated
 output respectively
 */
void test_find_up(){

  char grid[MAX_SIZE][MAX_SIZE];
  populate_grid(grid, "grid.txt");
  char wordtotest[]="pop";
  FILE* correct=fopen("correct.txt", "w");
  fprintf(correct, "pop 2 0 U\n");
  FILE* write_to_test=fopen("write_to_test.txt","w");
  find_up(grid, 4, wordtotest, write_to_test);

  
  assert( file_eq("correct.txt","write_to_test.txt"));                                     
fclose(correct);
    fclose(write_to_test);
 

}

/* tests find_all() by comparing correct.txt and write_to_test.txt which have the correct and the generated
 output respectively
 */
void test_find_all(){
 char grid[MAX_SIZE][MAX_SIZE];
 populate_grid(grid, "grid.txt");
 char wordtotest[]="pop";
 FILE* correct=fopen("correct.txt", "w");
 fprintf(correct,"pop 0 0 D\npop 2 0 U\n");
 FILE* write_to_test=fopen("write_to_test.txt","w");
 find_all(grid, 4, wordtotest, write_to_test);

fclose(correct);
    fclose(write_to_test); 
 assert( file_eq("correct.txt","write_to_test.txt"));

}
 

// tests to_lower() 
void test_to_lower() {
  int t=0;
  char test_lower[]="ABC";
  to_lower(test_lower);
  if(strcmp(test_lower,"abc")==0) {
    t=1;
  }
  
  
  assert(t);
}

// tests reverse()
void test_reverse() {
  int t=0;
  char testreverse[]={'a','b','c','\0'};
  reverse(testreverse);
  if(strcmp(testreverse,"cba")==0) {
    t=1;
  }

  
  assert(t);
}

