#include <iostream>
#include <iomanip>
#include "IntArray.h"

using namespace std;

ostream& operator<<(ostream&, const IntArray&); //stream insertion operator
istream& operator>>(istream&, IntArray&); //stream extraction operator

int main()
{
    /*
    int x; //variable -> memory reservation 
    int& y = x; //a reference variable cannot be declared without having an existing variable of the same type
    */

    IntArray a;
    cout << "Getting count with A: " << a.get_count() << endl; //outsider: can call a static function using an object
    //cout << IntArray::get_count() << endl;
    cout << "Values in array A: " << a << endl;

    IntArray b;
    cout << "Getting count with B: " << b.get_count() << endl;
    //cout << IntArray::get_count() << endl;
    cout << "Values in array B: " << b << endl;

    cout << "Enter new values for B: " << endl;
    cin >> b;

    IntArray c = a + b;
    cout << endl;
    cout << "The sum of A and B is: " << c << endl;

    if (a == b)
    {
        cout << "A and B are equal." << endl;
        cout << endl;
    }
    else
    {
        cout << "A and B are not equal." << endl;
        cout << endl;
    }
    
    //int value = a[0];
    cout << "Value at a[0] is: " << a[0] << endl;
    cout << endl;
    cout << "Value at a[2] is: " << a[2] << endl;
    cout << endl;

    cout << "B = A++" << endl;
    //b = a++;
    cout << "After pre-increment for A: " << a << endl;
    cout << "After pre-increment for B: " << b << endl;

    cout << "B = ++A" << endl;
    b = ++a;
    cout << "After post-increment for A: " << a << endl;
    cout << "After pre-increment for B: " << b << endl;

/*
    cout << "Get data for obj a" << endl;
    cin >> a;
    cout << "Display data for obj a" << endl;
    cout << a;
    cout << "Get data for obj b" << endl;
    cin >> b;
    cout << "Display data for obj b" << endl;
    cout << b;
*/
}
//not cout for the 1st argument because the output device can be monitor or ...
ostream& operator<<(ostream& out, const IntArray& a)
{
    out << "IntArray data: ";
    for (int i = 0; i < a.size; i++)
    {
        out << setw(3) << a.array[i];

    }
    out << endl; //not cout
    return out; // not cout
    //why return out, which is the first arg?
    //cout << a << b;
    //operator(cout,a); must return cout, so that cout << b can be performed
}
//cin >> a >> b;
istream& operator>>(istream& in, IntArray& a)
{
    cout << "Enter " << a.size << " integers: ";
    for (int i = 0; i < a.size; i++)
    {
        in >> a.array[i];
    }
    return in;
}