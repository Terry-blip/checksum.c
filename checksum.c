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
  char checksum;
  char complement;
  char header[10];

  read(0, header, 10);

  for (int i = 0; i < count; i++) {

    header[i] = (int) getchar();

        if (i == 5) {
            checksum = header[i];
        }
        else {
            sum = sum + header[i];
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