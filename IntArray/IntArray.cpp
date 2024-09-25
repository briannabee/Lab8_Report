#include <iostream>
#include "IntArray.h"

int IntArray::count = 0;

IntArray::IntArray()
{
   array = new int[5];
   size = 5;
   fill_array();
   count++;
}

IntArray::IntArray(int size)
{
    array = new int[size];
    this->size = size;
    fill_array();
    count++;
}

IntArray::IntArray(const IntArray& right)
{
    array = new int[right.size];
    size = right.size;
    
    //copy the values of the array (in the heap) of right --> deep copy
    for(int i=0; i < size; i++)
        {
            array[i] = right.array[i];
        }
        count++;
}

IntArray::~IntArray()
{
    delete[] array;
    count--;
}

//IntArray a;
//IntArray b(3);
//IntArray c;
//c = b = a;
//similar to the copy constructor, but we are not creating an object.
//work on existing objects
/*
IntArray& IntArray::operator=(const IntArray& right)
{
    if(right.size == this->size)
    {
        for(int i=0; i<size; i++)
        {
            array[i] = right.array[i];
        }
    }
    else
    {
        delete[] array;
        this->array = new int[right.size];
        size = right.size;
        for(int i = 0; i < size; i++)
        {
            array[i] = right.array[i];
        }
    }
    return *this;
}
*/
//pointer swapping technique
IntArray& IntArray::operator=(const IntArray& right)
{
//1. create a local object using copy constructor
IntArray local(right);
//2. swap array pointers and sizes
int* temp_array = this->array; //array
this->array = local.array;
local.array = temp_array;

int temp_size = this->size;
this->size = local.size;
local.size = temp_size;
//3. return *this;
return *this; //local is out of scope, which calls the destructor, deleting the original array of this
}

//c = a + b; element by element addition
IntArray IntArray::operator+(const IntArray& right)
{
    IntArray result(right.size);
    if(size == right.size)
    {
        for(int i=0; i < size; i++)
        {
            result.array[i] = array[i] + right.array[i];
        }
    }
    else
    {
        int large = (size > right.size) ? size : right.size;
        result = IntArray(large);
        for (int i = 0; i < large; i++)
        {
            if (i < size && i < right.size)
            {
                result.array[i] = array[i] + right.array[i];
            }
        }
        //if this->size != right.size, find the larger array
        //create a new array of the larger size.
    }
    return result; //local object --> return type IntArray without &
                    //result will be copied to the stack or a CPU register
                    //copy constructor will be called automatically.
}

//==: equal to, return must be a bool type  
//obj1 == obj2
bool IntArray::operator==(const IntArray& right)
{
    bool result = false;
    if (size == right.size)
    {
        int i;
        for(i = 0; i < size; i++)
        {
            if(array[i] != right.array[i])
                break;  
        }
        if (i == size)
        result = true;
    }
    return result;
}

//IntArray obj1; //assume that the array has 10, 20, 30
//obj[2] = 50; object1.operator[](2) ==> 30 = 50 if operator[](int) returns a value;
//left = right; right must be value, left must be a memory address.
//x = y;
//index operator
int& IntArray::operator[](int index)
{
    return array[index]; //are you returning the value or memory address or reference?
}

//IntArray a(3);
//a++; //post-increment; a = a +1; operator++(int); int is a dummy parameter just to distringuish pre from post
//++a; //pre-increment a = a + 1; operator++()
//a++ ==> a.operator++(int);
//++a ==> a.operator++();
//IntArray b(3);
//b = ++a;
    //the values of the array of b are the same values of the array of a
    // ==> b = a.operator();
//b = a++;
IntArray& IntArray::operator++()
{
    for(int i = 0; i < size; i++)
    {
        ++array[i];
    }
    return *this;
}

//return type is IntArray without & --> return a local object of IntArray
IntArray IntArray::operator++(int)
{
    //1. make a duplicate of this
    IntArray local(*this);
    //2. increment the elements of the array of this
    //this array is incremented
    for(int i = 0; i < size; i++)
    {
        ++array[i];
    }
    //3. return
    return local;

}

void IntArray::fill_array()
{
    for (int i = 0; i < size; i++)
    {
        array[i] = rand() % 100;
    }
}

int IntArray::get_count()
{
    return count;
}