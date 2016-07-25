#include <iostream>
#include "dlist.h"
#include "dlist.cpp"
#define CRTDBG_MAP_ALLOC    
#include <stdlib.h>    
#include <crtdbg.h>  
using namespace std;

int main(int argc, char *argv[])
{
    int result = 0;

    Dlist<int> ilist;
    int *ip = new int(1);
    ilist.insertFront(ip);

    ip = ilist.removeFront();
    if(*ip != 1)
        result = -1;
    delete ip;

    if(!ilist.isEmpty())
        result = -1;
	_CrtDumpMemoryLeaks();
    return result;
}
