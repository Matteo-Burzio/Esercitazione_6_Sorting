#pragma once

#include <iostream>
#include <vector>
#include<queue>

using namespace std;

namespace SortLibrary {

    template<typename T>
    // Specify that type T has to satisfy some requirement
    concept Sortable = requires(T& t)
    {
        // T must support the comparison operator
        // The result of < ha to be covertible to type bool
        {t < t} -> convertible_to<bool>;
    };

    // Bubble sort
    template<Sortable T>
    void bubble_sort(vector<T>& v)
    {
        // get vector size
        const unsigned int len = v.size();
        
        for(size_t i = 0; i < len - 1; i++)
        {
            for(size_t j = i + 1; j < len; j++)
            {
                if(v[j] < v[i])
                {
                    swap(v[i], v[j]);
                }
            }
        }
    }


    // Heap sort
    template<Sortable T>
    void heap_sort(vector<T>& v)
    {
        // get vector size
        const unsigned int len = v.size();

        // Initialize heap
        // by default the root is the largest element
        priority_queue<T> heap;

        // Fill the heap
        for(size_t i = 0; i < len; i++)
        {
            heap.push(v[i]);
        }
        
        // Counter variable
        unsigned int i = 0;

        // Empty it (returns it in descending order)
        while(!heap.empty())
        {
            // Get root
            v[i] = heap.top();

            // Remove root
            heap.pop();

            i++; // increase counter
        }

    // The vector has to be reversed
    reverse(v.begin(), v.end());
    }

}


