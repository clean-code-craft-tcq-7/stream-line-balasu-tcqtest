#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "sender_config.h"
#include "sender.h"
#include "fileoperations.h"

void sendSensorData(void (*fp_sender)(char*))
{
    char buffer[500];
    char sensTxt[50];
    int index = 0, valArrIdx;
    int minSampleCnt = 0;
    int samplesCnt[MAX_SENSOR_SUPPORTED];
    int sampleValArr[MAX_SENSOR_SUPPORTED];
    int sensorValue[MAX_SENSOR_SUPPORTED][50];

    sprintf(buffer, "%s\n",STREAM_HEADER);

    while(index < MAX_SENSOR_SUPPORTED)
    {
        samplesCnt[index] = readFile(sensorFileName[index], &sensorValue[index][0]);
        index++;
    }
    minSampleCnt = findMinInAnArray(samplesCnt, MAX_SENSOR_SUPPORTED);

    for(index = 0; index < minSampleCnt; index++)
    {
        valArrIdx = 0;
        while(valArrIdx < MAX_SENSOR_SUPPORTED)
        {
            sampleValArr[valArrIdx] = sensorValue[valArrIdx][index];
            valArrIdx++;
        }
        memset(sensTxt, 0, 50);
        frameValueAsCsv(sensTxt, sampleValArr, MAX_SENSOR_SUPPORTED);
        strcat(buffer,sensTxt);
    }

    fp_sender(buffer);
}


void frameValueAsCsv(char* buffer,int* sensorVal, int count)
{
    int index = 0;
    char buff[10];

    while(index < count)
    {
        sprintf(buff,"%d, ",sensorVal[index]);
        strcat(buffer, buff);
        index++;
    }
    buffer[strlen(buffer) - 2] = '\n';
    buffer[strlen(buffer) - 1] = '\0';
}

int findMinInAnArray(int* arr, int cnt)
{
    int idx;
    int min = arr[0];

    for(idx = 1; idx < cnt; idx++)
    {
        if(arr[idx] < min)
            min = arr[idx];
    }

    return min;
}
