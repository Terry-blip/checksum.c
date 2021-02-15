/********************************/
/* Program Name: Checksum.c     */
/* Author: Armand Minassian     */
/* Date:   Feb 14, 2021         */
/********************************/
/* Description: Checksum in .C  */
/* Validation Checks:           */
/* Enhancements:                */
/********************************/

#include "stdio.h"
#include "stdlib.h"
#include <unistd.h>

#define max_int (255)
#define byte (char)

int main (int argc, char * argv[], char ** envp) {

  int count = 10;
  int sum = 0;   
  int checksum = 0;
  int complement = 0;
  //int stdin;

  /* the following is the prototype for the read system call */
  //int read(int fildes, void *buf, size_t nbyte);



  for (int i = 0; i < count; i++) {

    //stdin = getchar;
    //int nextChar = stdin;

    int read(int fildes, void *buf, size_t nbyte);

        if (i == 5) {
            checksum = read;
        }
        else {
        sum = sum + read;
        }
  }

  complement = max_int - sum;

  fprintf(stdout, "Stored Checksum: %d, Computed Checksum: %d\n", checksum, complement);

  if (checksum != complement ) {
    fprintf(stderr, "Error Detected!\n"); 
    return 1;
  }

  return 0;
}