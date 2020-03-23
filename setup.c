/**
 * C program to create a file and write data into file.
 * Base Program is not my work, taken from https://codeforwin.org/2018/01/c-program-create-file-write-contents.html
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>

//  #define DATA_SIZE 1000

char * ext(char fname[])
{
    int index = 0;
    while (true)
    {
        if (fname[index] == '.')
        {
            return fname + index;
        }
        index += 1;
    }
}

char * nm(char fname[])
{
    int index = 0;
    static char string[100];

    while (true)
    {
        if (fname[index] == '.')
        {
            break;
        }
        string[index] = fname[index];

        index += 1;
    }

    return string;
}

bool equal(char s1[], char s2[])
{
    int index = 0;

    while (true)
    {
        if (s1[index] == '\0' && s2[index] == '\0')
        {
            return true;
        }

        if (s1[index] != s2[index])
        {
            return false;
        }

        if (s1[index] == '\0' ^ s2[index] == '\0')
        {
            return false;
        }

        index += 1;
    }
}

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
    char * filename = argv[1];
    char * name = nm(filename);
    char * extension = ext(filename);

    printf("filename: %s name: %s extension: %s\n", filename, name, extension);

    if (!exists("makefile") )
    {
        FILE * makefile;

        makefile = fopen("makefile", "a");
        if (makefile == NULL)
        {
            printf("Failed to create makefile\n");
            exit(EXIT_FAILURE);
        }

        char * compiler = equal(".c", extension)? "CC" : "CXX";
        char * flags = equal(".c", extension) ? "CFLAGS" : "CXXFLAGS";

        fprintf(makefile, "CC = gcc\
CXX = g++\
CFLAGS = -g\
CXXFLAGS = -g\
\
setup: setup.c\
 $(%s) $(%s) -o %s %s\
\
all: setup.c\
 $(%s) $(%s) -o %s %s\
\
clean:\
     rm -r %s %s%s", compiler, flags, name, filename, compiler, flags, name, filename, name, name, ".dSYM");

        fclose(makefile);
    } else
    {
        printf("makefile already exists\n");
    }
    
    if (!exists(".gitignore") )
    {
        FILE * gitignore;

        gitignore = fopen(".gitignore", "a");
        if (gitignore == NULL)
        {
            printf("Failed to create gitignore\n");
            exit(EXIT_FAILURE);
        }

        if (equal(".c", extension))
        {
            fprintf(gitignore, "# Prerequisites\
*.d\
\
# Object files\
*.o\
*.ko\
*.obj\
*.elf\
\
# Linker output\
*.ilk\
*.map\
*.exp\
\
# Precompiled Headers\
*.gch\
*.pch\
\
# Libraries\
*.lib\
*.a\
*.la\
*.lo\
\
# Shared objects (inc. Windows DLLs)\
*.dll\
*.so\
*.so.*\
*.dylib\
\
# Executables\
*.exe\
*.out\
*.app\
*.i*86\
*.x86_64\
*.hex\
\
# Debug files\
*.dSYM/\
*.su\
*.idb\
*.pdb\
\
# Kernel Module Compile Results\
*.mod*\
*.cmd\
.tmp_versions/\
modules.order\
Module.symvers\
Mkfile.old\
dkms.conf\
\
# .dSYM\
*.dSYM\
\
# .DS_Store\
.DS_Store\
\
# Swap files\
*.swp");
        } else
        {
            fprintf(gitignore, "# Prerequisites\
*.d\
\
# Compiled Object files\
*.slo\
*.lo\
*.o\
*.obj\
\
# Precompiled Headers\
*.gch\
*.pch\
\
# Compiled Dynamic libraries\
*.so\
*.dylib\
*.dll\
\
# Fortran module files\
*.mod\
*.smod\
\
# Compiled Static libraries\
*.lai\
*.la\
*.a\
*.lib\
\
# Executables\
*.exe\
*.out\
*.app\
\
# .dSYM\
*.dSYM\
\
# .DS_Store\
.DS_Store\
\
# Swap files\
*.swp");
        }

        fclose(gitignore);
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
