#include <chrono>
#include <iostream>
#include <random>
#include <vector>

// Sample function that we want to measure: sorting a vector
void bubbleSort(std::vector<int> &arr) {
  int n = arr.size();
  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < n - i - 1; j++) {
      if (arr[j] > arr[j + 1]) {
        std::swap(arr[j], arr[j + 1]);
      }
    }
  }
}

// Function to generate a random vector
std::vector<int> generateRandomVector(int size, int min = 0, int max = 1000) {
  std::vector<int> vec(size);
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> distrib(min, max);

  for (int i = 0; i < size; i++) {
    vec[i] = distrib(gen);
  }

  return vec;
}

// Method 1: Using chrono for microsecond precision
template <typename Func, typename... Args>
double measureExecutionTime(Func func, Args &&...args) {
  auto start = std::chrono::high_resolution_clock::now();

  func(std::forward<Args>(args)...);

  auto end = std::chrono::high_resolution_clock::now();

  auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

  return duration.count() / 1000.0;
}

// Method 2: Manual timing for specific sections of code
void demoManualTiming() {
  std::vector<int> testArray = generateRandomVector(10000);

  auto start = std::chrono::high_resolution_clock::now();

  bubbleSort(testArray);

  auto end = std::chrono::high_resolution_clock::now();

  auto duration =std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

  std::cout << "Manual timing: Bubble sort took " << duration.count() << " milliseconds" << std::endl;
}

// Method 3: Measuring average execution time over multiple runs
double measureAverageTime(int runs, int size) {
  double totalTime = 0.0;

  for (int i = 0; i < runs; i++) {
    std::vector<int> testArray = generateRandomVector(size);
    auto start = std::chrono::high_resolution_clock::now();

    bubbleSort(testArray);

    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    totalTime += duration.count();
  }

  return (totalTime / runs) / 1000.0; // Average time in milliseconds
}

int main() {
  // Demo of Method 1: Using the template function
  std::vector<int> arr1 = generateRandomVector(5000);
  std::vector<int> arr2 = arr1; // Make a copy for fair comparison

  double bubbleSortTime = measureExecutionTime(bubbleSort, arr1);
  std::cout << "Bubble sort took " << bubbleSortTime << " milliseconds" << std::endl;

  // Demo of Method 2: Manual timing
  demoManualTiming();

  // Demo of Method 3: Average time over multiple runs
  double avgTime = measureAverageTime(5, 5000);
  std::cout << "Average bubble sort time over 5 runs: " << avgTime
            << " milliseconds" << std::endl;

  return 0;
}