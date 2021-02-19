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
  char header[count];

  read(0, header, count);

  for (int i = 0; i < count; i++) {

    	unsigned char temp = (unsigned char) header[i];

		int carries = 0;

        if (i == 5) {
            checksum = temp;
            temp = 0;
        }


        if (sum >= max_int + 1) {

        	carries = 1;
    		sum = sum + temp;
			sum = sum - max_int;
			
        }

        else {

    		sum = sum + temp + carries;

        }

    }

 
  int quotient = sum / (max_int + 1);
  int remainder = sum % (max_int + 1);
  sum = quotient + remainder;
  complement = max_int - sum;
  
 fprintf(stdout, "Stored Checksum: %d, Computed Checksum: %d\n", checksum, complement);

  if (checksum != complement ) {
    fprintf(stderr, "Error Detected!\n"); 
    return 1;
  }

  return 0;
}
