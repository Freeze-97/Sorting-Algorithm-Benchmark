// IntArray

#ifndef LABORATION_4_INTARRAY_H
#define LABORATION_4_INTARRAY_H

// Laboratory 4
// Tommy Yasi/toya1800

#include "Timer.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <random>
#include <fstream>

class IntArray
{
private:
    int *arr; // Pekare till arrayen
    size_t maxSize; // Arrayens maximala storlek
    size_t size; // IntArrayens aktuella storlek
public:
    // ---------------- Konstruktorer och destruktor
    IntArray();
    IntArray (int pMaxSize);
    IntArray (const IntArray &a);
    ~IntArray();

    //------------------ Get- och set-funktioner
    size_t getMaxSize() const {return maxSize;}
    size_t getSize() const {return size;}
    int getValue(int idx) const;
    bool addValue(int value);

    // ----------------- Överlagra tilldelningsoperatorn
    const IntArray &operator=(const IntArray &a);

    // Randomize
    bool randomizeArray();

    // bubblesorting
    void bubblesort();
    void swap(int &a, int &b);
    // quicksort
    void quicksort(int first, int last);
    void q1(int n);
    // selectionsortort
    void selectionsort();
    // insertionsort
    void insertionsort();
};
const char DELIM = '|';

#endif //LABORATION_4_INTARRAY_H
