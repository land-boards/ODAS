/* ========================================
 *
 * Copyright Land Boards, LLC, 2016
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/

#include <cstdlib>
#include <iostream>

using namespace std;

#include "project.h"
#include "proEnv.h"
#include "mytypes.h"
#include "ARM_Monitor.h"
#include "pcSerialIO.h"
#include "accessMemory.h"

extern char myStringInMemory[];

int main(int argc, char *argv[])
{
//    system("PAUSE");
    initMemArray();
    while(1)
        ARM_Monitor();
    return EXIT_SUCCESS;
}
