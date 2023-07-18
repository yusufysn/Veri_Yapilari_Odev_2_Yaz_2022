#ifndef RADIX_HPP
#define RADIX_HPP

#include <iostream>
using namespace std;

class Radix {
private:
    // Function to get the largest element from an array
    int getMax(int array[], int n);

    // Using counting sort to sort the elements in the basis of significant places
    void countingSort(int array[], int size, int place);

public:
    // Main function to implement radix sort
    void radixsort(int array[], int size);

    // Print an array
    void printArray(int array[], int size);
};

#endif 
