#pragma once

#include <iostream>
#include <vector>
#include <gtest/gtest.h>
#include "SortingAlgorithm.hpp"

using namespace std;

namespace SortLibrary {

// Define a test for the bubble sort algorithm
TEST(TestSorting, TestBubbleSort)
{
    // Create a vector (not ordered)
    vector<int> v = {9, 13, 5, 10, 2, 7, 9, 4, 6, 12};

    // Run the algorithm
    bubble_sort<int>(v);

    // Write manually the ordered vector
    vector<int> sortedV = {2, 4, 5, 6, 7, 9, 9, 10, 12 ,13};

    // Check if the algorithm worked correctly
    EXPECT_EQ(v, sortedV);
}

// Same test as above, for the heap sort algorithm
TEST(TestSorting, TestHeapSort)
{
    std::vector<int> v = {9, 13, 5, 10, 2, 7, 9, 4, 6, 12};
    heap_sort<int>(v);
    std::vector<int> sortedV = {2, 4, 5, 6, 7, 9, 9, 10, 12 ,13};
    EXPECT_EQ(v, sortedV);
}

}
