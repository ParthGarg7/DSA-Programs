#include <iostream>
#include <vector>
using namespace std;

void Method1();
void Method2();
void Method3();

// This code is to show different methods of array creation in c++ programming
int main()
{
    Method1();
    cout << endl;
    Method2();
    cout << endl;
    Method3();
    cout << endl;
}

void Method1()
{
    // Basic array declaration (Creates a Static array)
    int Array[5] = {1, 2, 3};
    cout << "Method1" << endl;
    cout << "Array created using basic array declaration: " << endl;
    cout << "Array is" << endl;
    for (auto x : Array)
        cout << x << " ";
}

void Method2()
{
    // Dynamic array declaration (Creates a Dynamic array)
    // Dynamic array with the help of a pointer and new keyword

    int size;

    cout << "Method2" << endl;
    cout << "Array created using pointer and new keyword: " << endl;

    cout << "Enter the size of the array" << endl;
    cin >> size;
    int *Array = new int[size]; // dynamically allocating the memory

    // we can not use the for each loop in this method
    for (int i = 0; i < size; i++)
    {
        cout << "Enter element " << i + 1 << ": " << endl;
        cin >> Array[i];
    }

    cout << "Array is" << endl;
    for (int x = 0; x < size; x++)
        cout << Array[x] << " ";

    delete[] Array; // in this method the allocated memory have to freed manually by the use of delete
}

void Method3()
{
    // has to include the vector file first to use this method
    // #include <vector>
    // Dynamic array declaration (Creates a Dynamic array)
    // Dynamic array with the help of a vector
    // Deallocation of memory of the array will be done automatically
    /* In C++, a vector is a dynamic array provided by the Standard Template Library (STL).
    It is defined in the <vector> header and allows storing elements of the same data type in a contiguous memory block.*/

    cout << "Method3" << endl;
    cout << "Array created using vector: " << endl;

    // Creating a vector of integers
    // Declaring an empty vector of integers

    vector<int> Array; // declares a dynamic array so no need to define the size

    /*
    Common Operations on std::vector
    Operation	     Description
    .push_back(x)	 Adds x at the end
    .pop_back()	     Removes the last element
    .size()	         Returns the number of elements
    .capacity()	     Returns allocated memory slots
    .empty()	     Checks if vector is empty
    .clear()	     Removes all elements
    .insert(pos, x)	 Inserts x at pos
    .erase(pos)	     Removes element at pos
    .front()	     Returns first element
    .back()	         Returns last element
    */

    Array = {1, 2};
    Array.push_back(3);
    Array.push_back(4);
    Array.insert(Array.begin() + 4, 5); //  .begin is necessary to use inside the .insert

    cout << "Array is" << endl;
    for (int x = 0; x < Array.size(); x++)
        cout << Array[x] << " ";
}
