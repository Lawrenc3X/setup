#include <string,h>
#include <stdio.h>

#define MAKEFILE "CC = gcc\n"\
                 "CXX = g++\n"\
                 "CFLAGS = \n"\
                 "CXXFLAGS = \n"\
                 "\n"\
                 "%s: %s\n"\
                 "    $(%s) $(%s) -o %s %s\n"\
                 "\n"\
                 "all: %s\n"\
                 "    $(%s) $(%s) -o %s %s\n"\
                 "\n"\
                 "clean:\n"\
                 "    rm -r %s %s%s"

void createMakefile(FILE * makefile, char * files[], char flags[])
{
    char * compiler = strcmp(".c", extension) == 0 ? "CC" : "CXX";
    char * flags = strcmp(".c", extension) == 0 ? "CFLAGS" : "CXXFLAGS";
    fprintf(makefile, MAKEFILE, )
}

char * getExtension(char fname[])
{
    char * dot = strrchr(filename, '.');
    if (!dot || dot == filename) return "";
    return dot + 1;
}

char * getName(char fname[])
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
