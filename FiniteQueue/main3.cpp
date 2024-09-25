#include <iostream>
#include <cstdlib>
#include "FiniteQueue.h"

int main()
{
    const int SIZE = 5;
    FiniteQueue q1(SIZE); //5 is the capacity of the array

    //put a code under try if it may cause an exception
    try {
        for(int i = 0; i < 5; i++)
        {
            q1.push(rand() % 10); //QueueFullException
        }
    }
    catch(FiniteQueue::QueueFullException& excep)
    {
        std::cout << "QueueFullException occured\n";
    }
    
    try {
        for(int i = 0; i < 5; i++)
        {
            q1.pop(); //QueueEmptyException
        }
    }
    catch(FiniteQueue::QueueEmptyException& excep)
    {
        std::cout << "QueueEmptyException occured\n";
    }


    return 0;
}