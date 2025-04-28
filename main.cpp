#include <iostream>
#include <sstream>
#include <cmath>
#include <numeric>
#include <chrono>
#include "SortingAlgorithm.hpp"

using namespace std;

// Function to print vectors in a nice way
template<typename T>
string ArrayToString(const vector<T>& v)
{
    string str;
    ostringstream toString;
    toString << "[ ";
    for (const T& e: v)
        toString << e << " ";
    toString << "]";

    return toString.str();
}

// To pass parameters to main the standard syntax is:
// argc: number of arguments
// argv: array of arguments
// The first argument is always the executable file's name


int main(int argc, char *argv[])
{
    // Print number of arguments
    cout << "argc: " << argc << endl;

    // Print the arguments themselves
    for(int a = 0; a < argc; a++)
        cout << argv[a] << " ";
    cout << endl;    

    // Set default size if no argument is given
    size_t m = 10;

    if(argc > 1) // More than one argument
    {
        // Get second argument and save it in variable m
        istringstream istr(argv[1]);
        istr >> m;
        cout << "use value: "  << m << endl;
    }
    else
    {
        cerr << "use default value: "  << m << endl;
    }

    // Create vectors to test the algorithms

    // Vector 1: ordered
    // Iota gives integers starting from the third parameter
    // e.g. -4, -3, etc.
    vector<int> v1(m);
    std::iota(v1.begin(), v1.end(), -4);

    // Print the vector 
    cout << "v1: " << endl;
    cout << ArrayToString(v1) << endl;

    // Vector 2: random
    // Set the seed
    srand(42);

    vector<double> v2(m);
    for(size_t i = 0; i < m; i++)
    {
        // rand() gives a random int in [0,RAND_MAX]
        // By dividing we get a double in [0,1]
        v2[i] = rand() / ((double)RAND_MAX);
    }
         
    // Print the vector
    cout << "v2: " << endl;
    cout << ArrayToString(v2) << endl;

    // Vector 3: partially ordered
    vector<int> v3(m, 0);

    // Second half is randomized with values in [0,1000]
    for(size_t i = floor(m * 0.5) + 1; i < m; i++)
        v3[i] = rand() % 1000;

    // First half is copied from v1
    copy(v1.begin(), v1.begin() + floor(m * 0.5) + 1, v3.begin());

    // Print the vector
    cout << "v3: " << endl;
    cout << ArrayToString(v3) << endl;


    // Get current time
    const auto today_time = chrono::system_clock::now();

    // Print time passed in milliseconds since the default date
    cout << "Time passed since January 1, 1970: "
         << chrono::duration_cast<chrono::milliseconds>(
            today_time.time_since_epoch()).count() << endl;


    // Set the number of experiments to run
    unsigned int num_experiment = 100;

    // Initialize execution time
    double time_elapsed_selection_v1 = 0.0;

    // Bubble sort, vector 1
    for(unsigned int t = 0; t < num_experiment; t++)
    {
        // Create a copy of v1
        vector<int> v(v1);

        // Get start time
        chrono::steady_clock::time_point start_time = chrono::steady_clock::now();

        // Run the sorting algorithm
        SortLibrary::bubble_sort<int>(v);

        // Get finish time
        chrono::steady_clock::time_point end_time = chrono::steady_clock::now();

        // Add duration of the test to the time elapsed
        time_elapsed_selection_v1 += std::chrono::duration_cast<chrono::microseconds>(end_time - start_time).count();
    }

    // Take the average of the duration of the tests
    time_elapsed_selection_v1 /= num_experiment;

    // Print time it took to run
    cout << "Bubble Sort - v1: " << time_elapsed_selection_v1 << endl;

    // The following code does the same as the one commented above
    // It runs the two algorithms for the 3 vectors

    // Bubble sort, vector 2
    double time_elapsed_selection_v2 = 0.0;
    for(unsigned int t = 0; t < num_experiment; t++)
    {
        vector<double> v(v2);

        std::chrono::steady_clock::time_point start_time = std::chrono::steady_clock::now();
        SortLibrary::bubble_sort<double>(v);
        std::chrono::steady_clock::time_point end_time = std::chrono::steady_clock::now();
        time_elapsed_selection_v2 += std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count();
    }
    time_elapsed_selection_v2 /= num_experiment;

    cout << "Bubble Sort - v2: " << time_elapsed_selection_v2 << endl;


    // Bubble sort, vector 3
    double time_elapsed_selection_v3 = 0.0;
    for(unsigned int t = 0; t < num_experiment; t++)
    {
        vector<int> v(v3);

        std::chrono::steady_clock::time_point start_time = std::chrono::steady_clock::now();
        SortLibrary::bubble_sort<int>(v);
        std::chrono::steady_clock::time_point end_time = std::chrono::steady_clock::now();
        time_elapsed_selection_v3 += std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count();
    }
    time_elapsed_selection_v3 /= num_experiment;

    cout << "Bubble Sort - v3: " << time_elapsed_selection_v3 << endl;


    // Heap sort, vector 1
    double time_elapsed_insertion_v1 = 0.0;
    for(unsigned int t = 0; t < num_experiment; t++)
    {
        vector<int> v(v1);

        std::chrono::steady_clock::time_point start_time = std::chrono::steady_clock::now();
        SortLibrary::heap_sort<int>(v);
        std::chrono::steady_clock::time_point end_time = std::chrono::steady_clock::now();
        time_elapsed_insertion_v1 += std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count();
    }
    time_elapsed_insertion_v1 /= num_experiment;

    cout << "Heap Sort - v1: " << time_elapsed_insertion_v1 << endl;


    // Heap sort, vector 2
    double time_elapsed_insertion_v2 = 0.0;
    for(unsigned int t = 0; t < num_experiment; t++)
    {
        vector<double> v(v2);

        std::chrono::steady_clock::time_point start_time = std::chrono::steady_clock::now();
        SortLibrary::heap_sort<double>(v);
        std::chrono::steady_clock::time_point end_time = std::chrono::steady_clock::now();
        time_elapsed_insertion_v2 += std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count();
    }
    time_elapsed_insertion_v2 /= num_experiment;

    cout << "Heap Sort - v2: " << time_elapsed_insertion_v2 << endl;


    // heap sort, vector 3
    double time_elapsed_insertion_v3 = 0.0;
    for(unsigned int t = 0; t < num_experiment; t++)
    {
        vector<int> v(v3);

        std::chrono::steady_clock::time_point start_time = std::chrono::steady_clock::now();
        SortLibrary::heap_sort<int>(v);
        std::chrono::steady_clock::time_point end_time = std::chrono::steady_clock::now();
        time_elapsed_insertion_v3 += std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count();
    }
    time_elapsed_insertion_v3 /= num_experiment;

    cout << "Heap Sort - v3: " << time_elapsed_insertion_v3 << endl;


    return 0;
}


