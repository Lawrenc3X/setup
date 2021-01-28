#include <setup.h>
#include <unistd.h> 

int main(int argc, char * argv[])
{
    makefile = fopen("makefile", "w");
    if (makefile == NULL)
    {
        printf("Failed to create makefile\n");
        exit(EXIT_FAILURE);
    }

    createMakefile(makefile, files, flags);

    fclose(makefile);

    return 0;
}
