#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "sender_config.h"
#include "sender.h"
#include "fileoperations.h"
#include "test_cases.h"

char test_buff[200];

void test_print(char* buff)
{
    strcpy(test_buff, buff);
}

void test_functions(void)
{
    test_sensorRead();
    test_sender();
}

void test_sensorRead(void)
{
    // The sensor values will be stored in files with "," separated.
    int sensor1[10];
    int count = 0;
    const char* file = "TempSensor_Test.txt";

    count = readFile(file, sensor1);
    assert(count == 3);
    assert(sensor1[0] == 25);
    assert(sensor1[1] == 26);
    assert(sensor1[2] == 27);
}

void test_sender(void)
{
    memset(test_buff,0,200);
    strcpy((char*)sensorFileName[0], "TempSensor_Test.txt");
    strcpy((char*)sensorFileName[1], "SOCSensor_Test.txt");
    int val[] = {25,30,35};

    // Frame multiple sensor values in csv format
    frameValueAsCsv(test_buff, val, 3);
    assert(strcmp(test_buff,"25, 30, 35\n") == 0);

    //test case to find the min value in an array function
    assert(findMinInAnArray(val,3) == 25);
    int val1[] = {50,50,50};
    assert(findMinInAnArray(val1,3) == 50);
    int val2[] = {19,10,12};
    assert(findMinInAnArray(val2,3) == 10);

    // Test case for the csv header
    sendSensorData(&test_print);
    assert(strncmp(test_buff,STREAM_HEADER,strlen(STREAM_HEADER)) == 0);

    // Test the two sensor data output in csv format with 3 sample data
    memset(test_buff,0,200);
    sendSensorData(&test_print);
    assert(strcmp(test_buff,"Battery Temperature, SOC Value\n25, 10\n26, 11\n27, 12\n") == 0);
}
