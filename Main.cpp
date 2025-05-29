// Laboratory 4
// Tommy Yasi/toya1800

#include "Timer.h"
#include "IntArray.h"
#include <vector>
#include <functional>
#include <iomanip>
#include <fstream>
using namespace std;

// Benchmarking function
void benchmarkSort(const string& sortName, function<void(IntArray&)> sortFunction, const vector<int>& sizes, ofstream& outFile, Timer& timer) {
    for (int size : sizes) {
        double sumTime = 0;

        for (int i = 0; i < 10; i++) {
            IntArray array(size);
            array.randomizeArray();

            timer.start();
            sortFunction(array);  // Run the sort
            sumTime += timer.stop() / 1'000'000.0; // Convert µs to seconds
        }

        cout << fixed << setprecision(6);
        cout << "Sorting time: " << sumTime / 10 << " [s] "
             << "Average for 10 sortings of " << size << " elements." << endl;

        outFile << sortName << "  " << size << "  " << sumTime / 10 << endl;
    }
}

int main() {
    Timer timer;
    vector<int> sizes = {5000, 10000, 15000, 20000, 25000, 30000, 35000, 40000};

    ofstream outFile("sortSystems.txt");

    vector<pair<string, function<void(IntArray&)>>> sortFunctions = {
        {"bubblesort", [](IntArray& arr) { arr.bubblesort(); }},
        {"quicksort",  [](IntArray& arr) { arr.quicksort(0, arr.getMaxSize() - 1); }},
        {"selectionsort", [](IntArray& arr) { arr.selectionsort(); }},
        {"insertionsort", [](IntArray& arr) { arr.insertionsort(); }}
    };

    for (const auto& [name, func] : sortFunctions) {
        cout << "\n-- " << name << " --" << endl;
        benchmarkSort(name, func, sizes, outFile, timer);
    }

    outFile.close();
    return 0;
}