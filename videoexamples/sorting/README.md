# Module 10 - Sorting (C++ Version)

## Overview

This module contains C++ implementations of 5 common sorting algorithms:

- Selection Sort
- Insertion Sort
- Bubble Sort
- Merge Sort
- Quick Sort

## Source Files

**Core Sorting Module:**

- `Sorting.h` - Header file with template-based sorting algorithms
- `PlayingCard.h / PlayingCard.cpp` - PlayingCard class (includes operator overloads for comparison)
- `Deck.h / Deck.cpp` - Deck class for managing collections of cards

**Supporting Files:**

- `HandOfCards.h` - Abstract base class (interface equivalent)
- `SortingTester.cpp` - Test program demonstrating insertion sort on random integers

## Key Features

### Template-Based Design

All sorting methods are templates that work with any comparable type:

```cpp
template <typename T>
static void selectionSort(std::vector<T>& data);
```

### Helper Methods

- `isSorted(data)` - Verify if array is sorted
- `isSorted(data, min, max)` - Verify partial array range
- Comparison operators: `<`, `<=`, `>`
- `swap()` - Exchange two elements

### Supported Methods

1. **Selection Sort** - Find minimum, swap to position
2. **Insertion Sort** - Build sorted list by inserting elements
3. **Bubble Sort** - Compare adjacent elements, bubble largest to end
4. **Merge Sort** - Divide and conquer with merge step
5. **Quick Sort** - Partition around pivot element

## Compilation

### Compile SortingTester

```bash
g++ -std=c++17 -o SortingTester SortingTester.cpp PlayingCard.cpp Deck.cpp
```

### Run

```bash
./SortingTester
```

## Code Examples

### Sorting an array of integers

```cpp
std::vector<int> data = {5, 2, 8, 1, 9};
Sorting::insertionSort(data);
```

### Sorting a custom type (PlayingCard)

```cpp
std::vector<PlayingCard> cards;
cards.push_back(PlayingCard(5, 1));
cards.push_back(PlayingCard(3, 2));
Sorting::mergeSort(cards);
```

### Using range-based sorting

```cpp
// Sort only elements from index 0 to 50
Sorting::bubbleSort(data, 0, 50);
```

## Algorithm Complexity

| Algorithm | Best Case | Average Case | Worst Case |
| ----------- | ----------- | -------------- | ----------- |
| Selection | O(n²) | O(n²) | O(n²) |
| Insertion | O(n) | O(n²) | O(n²) |
| Bubble | O(n) | O(n²) | O(n²) |
| Merge | O(n log n) | O(n log n) | O(n log n) |
| Quick | O(n log n) | O(n log n) | O(n²) |

## C++ vs Java Notes

- **Vectors vs ArrayLists**: C++ uses `std::vector` for dynamic arrays
- **Templates vs Generics**: C++ templates are instantiated at compile time
- **Pass by Reference**: Use `&` to modify original data: `void sort(std::vector<T>& data)`
- **Operator Overloading**: PlayingCard implements `<`, `>`, `==` operators instead of `compareTo()`

## Important Concepts

1. **In-place Sorting**: All algorithms modify the original vector
2. **Comparison-Based**: Assumes elements implement `operator<`
3. **Stability**: Selection, Insertion, Bubble sorts are stable; others may not be
4. **Space Complexity**: Merge sort requires O(n) extra space; others are O(1)
