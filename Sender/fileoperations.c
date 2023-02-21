#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "fileoperations.h"

int readFile(const char* filePath, int* data)
{
    FILE* fl;
    long fl_size;
    char * buffer;
    char * strtok_res;
    int count = 0;

    fl = fopen ( filePath , "r+" );
    fseek (fl , 0 , SEEK_END);
    fl_size = ftell (fl);
    rewind (fl);

    buffer = (char*) malloc (sizeof(char)*fl_size);

    fread(buffer,1,fl_size,fl);

    strtok_res = strtok(buffer, ",");
    while (strtok_res != NULL)
    {
        *data = atoi(strtok_res);
        data++;
        count++;
        strtok_res = strtok (NULL, ",");
    }

    fclose (fl);

    return count;
}

void printToConsole(char* buff)
{
    write(STDOUT_FILENO, buff, strlen(buff));
}
