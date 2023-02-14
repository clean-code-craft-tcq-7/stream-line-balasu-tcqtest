#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "test/catch.hpp"
#include <stdio.h>
#include <string.h>
#include "sender.h"


TEST_CASE("Read sensor samples from file. Check first 3 samples")
{
    // The sensor values will be stored in files with "," separated.
    // There will be 50 samples of data stored for each sensor in two different files

    int sensor1[10];
    int count = 0;

    count = readFile("sensor1.txt", sensor1);
    REQUIRE(count, 3);
    REQUIRE(sensor1[0], 10);
    REQUIRE(sensor1[1], 11);
    REQUIRE(sensor1[2], 12);
}
