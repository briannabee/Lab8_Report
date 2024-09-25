#ifndef FINITE_QUEUE_H
#define FINITE_QUEUE_H
class FiniteQueue //FIRST IN, FIRST OUT
{
private:
    int* array;
    int first; //the index of the array where the first element is located
    int last; //last element
    int capacity; //the capacity of the array
    int size; //how many values actually occupies the array
public:
    FiniteQueue();
    FiniteQueue(int); //size of an array
    FiniteQueue(const FiniteQueue&);
    virtual ~FiniteQueue();

    //empty inner class for exception handling
    //The definition of a class A cannot contain a definition of another class;
    //except when B's body is empty
    class QueueEmptyException {};
    class QueueFullException {};

    void push(int); //enqueue
    void pop(); //dequeue
    bool is_empty();
    bool is_full();
};
#endif