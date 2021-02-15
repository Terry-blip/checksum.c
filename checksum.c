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
  unsigned char checksum;
  unsigned char complement;
  char header[10];
  int quotient = 0;
  int remainder = 0;

  read(0, header, 10);

  for (int i = 0; i < count; i++) {

    	unsigned char temp = (unsigned char) header[i];

        if (i == 5) {
            checksum = temp;
        }
        else {
            sum = sum + temp;
        }
        fprintf(stdout, "DEBUG OF TEMP: %d, DEBUG OF SUM %d\n", temp, sum);
  }

  quotient = sum / (max_int + 1);
  remainder = sum % (max_int + 1);
  sum = quotient + remainder;
  complement = max_int - sum;

fprintf(stdout, "%d, %d\n", max_int, sum);

 fprintf(stdout, "Stored Checksum: %d, Computed Checksum: %d\n", checksum, complement);

  if (checksum != complement ) {
    fprintf(stderr, "Error Detected!\n"); 
    return 1;
  }

  return 0;
}
