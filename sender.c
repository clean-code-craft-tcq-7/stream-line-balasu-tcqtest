#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "sender_config.h"
#include "sender.h"
#include "fileoperations.h"

void sendSensorData(void (*fp_sender)(char*))
{
    char buffer[200];

    sprintf(buffer, "%s\n",STREAM_HEADER);

    fp_sender(buffer);
}
