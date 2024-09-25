#ifndef INTARRAY_H
#define INTARRAY_H

#include <iostream>
using namespace std;

//If a class has a pointer as its member variable
//the pointer is likely to a memory in the heap.
//Then, you need to provide the BIG-THREE:
//1. copy constructor: deep copy
//2. operator=(): deep copy
//3. destructor: release the heap memory
//object1 = object2 without operator=(): member-wise assignment
//intArray1 = intArray2
//intArray intArray1(intArray2);

class IntArray {
  private:
    int* array;
    int size; // size of the array
    void fill_array();
    static int count; //keep track of the number of objects of IntArray

  public:    
    IntArray();                // default constructor
    IntArray(int);            //arg constructor
    
    IntArray(const IntArray&); // copy constructor
    virtual ~IntArray();               // destructor

    //functions that overload an operator --> give a new meaning to the operator or class
    IntArray& operator=(const IntArray&); // overloaded =    
    //IntArray = a; //default array size = 5
    //IntArray b(3); //the array size = 3;
    //IntArray c;
    //b = a; //object2-object1 ==> b.operator=(a);
    //c = b = a; (a->b and THEN b->c) same as b=a; c=b;
    //b.operator=(a); --> must return b as an object, not the address of the b
    //                    return (&this);    //IntArray&; not InArray without &

    IntArray operator+(const IntArray&);  // overloaded +
    bool operator==(const IntArray&);     // overloaded ==
    int& operator[](int);                 // overloaded [ ]
    IntArray& operator++();		  // overloaded ++ (pre increment); returns reference of IntArray
    IntArray operator++(int);		  // overloaded ++ (post increment); return local value of IntArray

  //The return type of a member function
  //1. IntArray = returns a local object of IntArray
  //2. IntArray& = returns (*this)
    static int get_count();
    
    // overloaded >> and << operators
    //friend : not a member of the class -> can't access private members
    // with the exception of friend functions
    //operator<<(): cout or file out of an object that you define (output!)
    //operator>>(): cin or fine in 
    //the argument of operator<<: ostream& --> not IntArray class
    //Not an instance member function --> no access to this
    //  you have to pass an object as the second argument
    friend ostream& operator<<(ostream&, const IntArray&); //cout << a
    friend istream &operator>>(istream&, IntArray&); //cin >> a, changing a, thus no const
  
};

#endif
