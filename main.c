#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "sender.h"
#include "test_cases.h"


int main(int argc, char **argv)
{
    if(argc == 1)
    {
        printf("Usage: %s [-t] [-r]\n", argv[0]);
        exit(0);
    }

    if(strcmp(argv[1],"-t") == 0)
    {
        test_functions();
    }

    return 0;
}
