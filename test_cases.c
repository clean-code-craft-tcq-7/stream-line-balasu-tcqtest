#include <stdio.h>
#include <string.h>
#include <assert.h>
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
    const char* file = "sensor1.txt";

    count = readFile(file, sensor1);
    assert(count == 3);
    assert(sensor1[0] == 10);
    assert(sensor1[1] == 11);
    assert(sensor1[2] == 12);
}

void test_sender(void)
{
    // No sensor values are processed yet
    // Only the csv header will be packed in the send buffer
    sendSensorData(&test_print);
    assert(strcmp(test_buff,"Battery Temperature, Charge Rate\n") == 0);
}
