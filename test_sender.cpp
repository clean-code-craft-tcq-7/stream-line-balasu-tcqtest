#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "test/catch.hpp"
#include <stdio.h>
#include <string.h>
#include "sender.h"


TEST CASE("Read sensor samples from file. Check first 3 samples")
{
    // The sensor values will be stored in files with "," sepearted.
    // There will be 50 samples of data stored for each sensor in two different files
    //
    int sensor1[3];
    int cmpResult = -1;

    REQUIRE(sensor1[0], 10);
    REQUIRE(sensor1[1], 11);
    REQUIRE(sensor1[2], 12);

}
