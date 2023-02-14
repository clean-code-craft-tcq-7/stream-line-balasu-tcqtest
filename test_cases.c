#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "sender.h"
#include "test_cases.h"


void test_functions(void)
{
    test_sensorRead();
}

void test_sensorRead(void)
{
    // The sensor values will be stored in files with "," separated.
    // There will be 50 samples of data stored for each sensor in two different files
    int sensor1[10];
    int count = 0;
    char* file = "sensor1.txt";

    count = readFile(file, sensor1);
    assert(count == 3);
    assert(sensor1[0] == 10);
    assert(sensor1[1] == 11);
    assert(sensor1[2] == 12);

}
