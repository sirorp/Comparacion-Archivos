
/******************************************************************************
*   simple_diff.c
*
*   This source compare two files character by character
*   
*   ( First Try )
*
*   by Pastor E. Ortega G.
*   Nov 2016
*
******************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <linux/hdreg.h>
 
int main(int argc, char *argv[]) {

   FILE *fp1, *fp2;     /* File Pointer's Definitions */
   int   ch1,  ch2;     /* Vars to Read from files    */
   char fname1[40], fname2[40];  /* Vars files name   */

   strcpy( fname1, argv[1]);     
   strcpy( fname2, argv[2]);     

   fp1 = fopen(fname1, "r");
   fp2 = fopen(fname2, "r");
 
   if (fp1 == NULL) {
      printf("\n Cannot open [%s] ", fname1);
      exit(1);
   } else if (fp2 == NULL) {
      printf("\n Cannot open [%s] ", fname2);
      exit(1);
   } else {
      ch1 = getc(fp1); /* Get the first charter from First  file */
      ch2 = getc(fp2); /* Get the first charter from Second file */
 
      while ((ch1 != EOF) && (ch2 != EOF) && (ch1 == ch2)) {
         ch1 = getc(fp1);
         ch2 = getc(fp2);
      }
 
      fclose(fp1); /* Close File Pointer */
      fclose(fp2); /* Close File Pointer */

      if (ch1 == ch2)
         printf("\n [%s] == [%s] Identical ", fname1,fname2);
      else if (ch1 != ch2)
         printf("\n Has some different \n");
    }
   return (0);
}