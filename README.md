# 📊 Sorting Algorithm Benchmark

## 📋 Description

This program benchmarks the performance of four classic sorting algorithms:

- **Bubble Sort**
- **Quick Sort**
- **Selection Sort**
- **Insertion Sort**

Each algorithm is tested with arrays of increasing size, and the results are averaged over 10 runs per size.

## ⚙️ How It Works

1. The array sizes tested are:  
   `5000`, `10000`, `15000`, `20000`, `25000` `30000`, `35000`, `40000`.

2. For each size:
   - A new random array is generated 10 times.
   - The selected sorting algorithm is applied.
   - The execution time is measured in microseconds using the `Timer` class.
   - The average time for 10 runs is calculated and displayed.

3. The results are:
   - Printed to the console.
   - Written to the file `sortSystems.txt` in the format:
     ```
     <algorithm>  <size>  <average_time>
     ```

## ✅ Compile & Run

Make sure all `.cpp` and `.h` files are in the same directory.

### Compile (Linux/macOS):
```bash
g++ main.cpp Timer.cpp IntArray.cpp -o sort_benchmark
./sort_benchmark
```

### Compile (Windows, with g++):
```bash
g++ main.cpp Timer.cpp IntArray.cpp -o sort_benchmark.exe
sort_benchmark.exe
```
