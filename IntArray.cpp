// Laboratory 4
// Tommy Yasi/toya1800
#include "IntArray.h"
using namespace std;

// Function-definitions
IntArray::IntArray(): maxSize(0), size(0) {
    arr = nullptr;
}
IntArray::IntArray (int pMaxSize): maxSize(pMaxSize), size(0) {
    arr = new int[maxSize];
}
IntArray::IntArray (const IntArray &a): maxSize(a.maxSize), size(a.size) {
    arr = new int[a.maxSize];
    for (int i=0; i<a.size; i++)
        arr[i] = a.arr[i];
}
IntArray:: ~IntArray() {
    delete [] arr;
    arr = nullptr;
}
int IntArray::getValue(int idx) const {
    return arr[idx];
}
bool IntArray::addValue(int value) {
    bool valueAdded = false;
    if(size < maxSize) {
        arr[size] = value;
        size++;
        valueAdded = true;
    }
    return valueAdded;
}
const IntArray &IntArray::operator=(const IntArray &a) {
    if(this != &a) {
        delete []arr;
        arr = new int[a.maxSize];
        maxSize = a.maxSize;
        size = a.size;
        for (int i=0; i < a.size; i++)
            arr[i] = a.arr[i];
    }
    return *this;
}
bool IntArray::randomizeArray() {
    default_random_engine generator(static_cast<unsigned>(time(nullptr)));
    uniform_int_distribution<int> random(0, maxSize-1);

    bool randomValuesAdded = false;
    if(size < maxSize)
    {
        for (int i=0; i < maxSize; i++){
            addValue(random(generator));
        }
        randomValuesAdded = true;
    }
    return randomValuesAdded;
}
void IntArray::bubblesort() {
    for(int pass=0; pass < size-1; pass++)
        for(int i=0; i < size-1; i++)
            if(arr[i] > arr[i+1]) {
                swap(arr[i], arr[i+1]);
            }
}
void IntArray::swap(int &a, int &b) {
    int tmp = a;
    a = b;
    b = tmp;
}
void IntArray::quicksort(int first, int last) {
    if(first < last) {
        int low = first;
        int high = last;
        if(arr[first] > arr[last])
            swap(arr[first], arr[last]);

        do {
            do{ low++; }while(arr[low] < arr[first]);
            do{ high--;}while(arr[high] > arr[first]);
            if(low < high)
                swap(arr[low], arr[high]);
        }while(low <= high);

        swap(arr[first], arr[high]);

        quicksort(first, high-1);
        quicksort(high+1, last);
    }
}
void IntArray::q1(int n) {
    quicksort(0,n-1);
}
void IntArray::selectionsort() {
    int smallIdx = 0;
    for(int i=0; i < size - 1; i++) {
        smallIdx = i; //Index för det minsta elementet till höger om pos i
        for( int j= i+1; j < size; j++) // Sök det minsta "osorterade" elementet
            if(arr[j] < arr[smallIdx])
                smallIdx = j; // Spara index för det minsta elementet

        if(smallIdx != i) // Byt plats om det fanns något mindre än a[i]
            swap(arr[i], arr[smallIdx]);
    }
}
void IntArray::insertionsort() {
    int i, key, j;
    for (i = 1; i < size; i++) {
        key = arr[i];
        j = i-1;
        while (j >= 0 && arr[j] > key) {
            arr[j+1] = arr[j];
            j = j-1;
        }
        arr[j+1] = key;
    }
}


