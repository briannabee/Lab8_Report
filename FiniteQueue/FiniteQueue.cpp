#include <iostream>
#include "FiniteQueue.h"

//using namespace std;
FiniteQueue::FiniteQueue()
{
    capacity = 5;
    array = new int[capacity];
    first = 0;
    last = capacity - 1;
    size = 0;
}
FiniteQueue::FiniteQueue(int c)
{
    capacity = c;
    array = new int[capacity];
    first = 0;
    last = capacity - 1;
    size = 0;
}
FiniteQueue::FiniteQueue(const FiniteQueue& right)
{
    capacity = right.capacity;
    array = new int[capacity];
    for (int i = 0; i < capacity; i++)
    {
        array[i] = right.array[i];
    }
    first = right.first;
    last = right.last;
    size = right.size;
}
FiniteQueue::~FiniteQueue()
{
    delete[] array;
}
void FiniteQueue::push(int value) //last index 
{
    if(is_full())
        throw QueueFullException();
    //normal situation where the queue is not full
    last = (++last) % capacity;
    array[last] = value;
    size++;
    std::cout << "push() called: " << &array[last] << std::endl;
}
void FiniteQueue::pop() //first
{
    if(is_empty())
    {
        throw QueueEmptyException(); //the call of the defauly constructor
                                    //when the throw statement is executed, immediately returns to main() function, like break;
    }
    //normal situation where the queue is not empty
    //if (first == capacity)
    std::cout << "pop() called: " << &array[first] << std::endl;
    first = (++first) % capacity;
    size--;
}
bool FiniteQueue::is_empty()
{
    return (size == 0);
}
bool FiniteQueue::is_full()
{
    return (size == capacity);
}