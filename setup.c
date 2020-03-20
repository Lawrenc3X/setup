/**
 * C program to create a file and write data into file.
 * Base Program is not my work, taken from https://codeforwin.org/2018/01/c-program-create-file-write-contents.html
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>

//  #define DATA_SIZE 1000

bool exists(const char *fname)
{
    if(access(fname, F_OK) != -1)
    {
        return true;
    } else
    {
        return false;
    }
}

int main(int argc, char * argv[])
{
    if (!exists("makefile") )
    {
        FILE * makefile;

        makefile = fopen("makefile", "a");
        if (makefile == NULL)
        {
            printf("Failed to create makefile\n");
            exit(EXIT_FAILURE);
        }

        // code
    } else
    {
        printf("makefile already exists\n");
    }
    
    if (!exists(".gitignore") )
    {
        FILE * gitignore;
        printf("yes\n");

        gitignore = fopen(".gitignore", "a");
        if (gitignore == NULL)
        {
            printf("Failed to create gitignore\n");
            exit(EXIT_FAILURE);
        }

        // code
    } else
    {
        printf("gitignore already exists\n");
    }

//     /* Variable to store user content */
//     char data[DATA_SIZE];
// 
//     /* File pointer to hold reference to our file */
//     FILE * fPtr;
// 
//     /* 
//      * Open file in w (write) mode. 
//      * "data/file1.txt" is complete path to create file
//      */
//     fPtr = fopen("file1.txt", "a");
// 
// 
//     /* fopen() return NULL if last operation was unsuccessful */
//     if(fPtr == NULL)
//     {
//         /* File not created hence exit */
//         printf("Unable to create file.\n");
//         exit(EXIT_FAILURE);
//     }
// 
// 
//     /* Input contents from user to store in file */
//     printf("Enter contents to store in file : \n");
//     fgets(data, DATA_SIZE, stdin);
// 
// 
//     /* Write data to file */
//     fputs(data, fPtr);
// 
// 
//     /* Close file to save file data */
//     fclose(fPtr);
// 
// 
//     /* Success message */
//     printf("File created and saved successfully. :) \n");

    return 0;
}
