#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <ratio>
#include <chrono>

using namespace std;

using namespace std::chrono;

#define ARRAY_SIZE 1000

#define KEYS_SIZE 1000

#define MIN 0
#define MAX 10000

int random(int min, int max) {
    return min + int((max - min + 1) * rand() / (RAND_MAX + 1.0));
}

void createRandomArray(int*& t, int n, int l, int h) {
    t = new int[n];

    for (int i = 0; i < n; i++) {
        t[i] = random(l, h);
    }
}

void printArray(int t[], int n) {
    for (int i = 0; i < n; i++) {
        cout << t[i] << " ";
    }
    cout << endl;
}

int compare(const void* a, const void* b)
{
    return (*(int*)a - *(int*)b);
}

int linearSearch(int t[], int l, int r, int key)
{
    //iteratively check from the element at position l to r
    //if the key is found return it

    // Key not found 
    return 0;
}

int linearSearchR(int t[], int l, int r, int key) {

    //Check if you reached the end of the array
    //if yes, return -1

    // Otherwise, check if key is present at the l position
    //return it if it is found
  
    // call the function again by omitting the item you checked above
    return 0;
}

int binarySearch(int t[], int l, int r, int key)
{
    int mid;
    //check if you have not reach the end of the array
    //if not
        // Find the mid
        

        // Check if key is present at the mid

        // If the key lies in between l and mid
        //adjust l accordingly
       
        // If tThe key lies in between mid and r
        //adjust r accordingly
       
    
    // if the key is not found, return -1

    return 0;
}

int binarySearchR(int t[], int l, int r, int key) {
    //check if you are at the end of the array
    //if not
        // Find  mid

        // Check if key is present at the mid
        //return it if it does
        

        // Check if the key lies in between l and mid
        // if yes, recursively call binary search with the elements between l and mid
        
        // Otherwise, the key lies in between and mid and r
        // Recursively call binary search with the elements between mid and r
          
    // if the key is not found, return -1
    return 0;
}

int ternarySearch(int t[], int l, int r, int key)
{
    int mid1, mid2;

    //check if you are at the end of the array
    //if not
    
        // Find  mid1 and mid2         

        // Check if key is present at any mid and return it

        // check where the key lies and iteratively repeat
        // The key lies in between l and mid1
        //adjust r accordingly

        // The key lies in between mid2 and r 
        // adjust l accordingly
        
        // The key lies in between mid1 and mid2 
        // adjust both l and r accordingly
    
    // if the key is not found, return -1
    return 0;
}

int ternarySearchR(int t[], int l, int r, int key)
{
    //check if you are at the end of the array
    //if not

        // Find  mid1 and mid2 

        // Check if key is present at any mid and return it

        // check where the key lies and recursively repeat
        // The key lies in between l and mid1 
       
        // The key lies in between mid2 and r 
        
        // The key lies in between mid1 and mid2 
        

    // if the key is not found, return -1
    return 0;
}


int main()
{
    srand(123456);

    int* keys;
    createRandomArray(keys, KEYS_SIZE, MIN, MAX);
    
    int* array = NULL;    

    //temp var to store the position of the element we search
    int keypos = -1;

    high_resolution_clock::time_point start, finish;
    duration<double> duration; 

    //initialize array with random numbers
    createRandomArray(array, ARRAY_SIZE, MIN, MAX);

    //time linear search iterative
    start = high_resolution_clock::now();
    for (int keyIndex = 0; keyIndex < KEYS_SIZE; keyIndex++) {
        keypos = linearSearch(array, 0, ARRAY_SIZE, keys[keyIndex]);
    }
    finish = high_resolution_clock::now();
    duration = finish-start;
    cout << "linear search iterative for "<<ARRAY_SIZE<< " ints: " << duration.count() << " s\n";


    //time linear search recursive

    
    //time binary search iterative
    qsort(array, ARRAY_SIZE, sizeof(int), compare);

    
    //time binary search recursive
    qsort(array, ARRAY_SIZE, sizeof(int), compare);

    
    //time ternary search iterative
    qsort(array, ARRAY_SIZE, sizeof(int), compare);

    
    //time ternary search recursive
    qsort(array, ARRAY_SIZE, sizeof(int), compare);
        

    

    /*
    ofstream resultsfile("results.txt");
    if (resultsfile.is_open())
    {
        //output the results
        for (int i = 0; i < algorithmsCount; i++) {
            resultsfile << algorithms[i].name << ",";
            for (int j = 0; j < sizeof(arraySizes) / sizeof(arraySizes[0]); j++)
                resultsfile << fixed << results[i][j].count() << ",";
            resultsfile << "\n";
        }
        resultsfile.close();
    }
    else cout << "Unable to open file";
    */

}






