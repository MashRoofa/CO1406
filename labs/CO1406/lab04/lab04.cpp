#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <ratio>
#include <chrono>

using namespace std;

using namespace std::chrono;

#define KEYS_SIZE 1000

#define MIN 0
#define MAX 10000

#define MAX_RECURSIVECALLS 3000

int counterRecursiveCalls = 0;

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
    for (int i = l; i < r; i++)
        if (t[i] == key) 
            return i;
    
    // Key not found 
    return -1;
}

int linearSearchR(int t[], int l, int r, int key) {
    counterRecursiveCalls++;

    //Check if at the end of the array
    if (l == r)       
        // Key not found 
        return -1;
    
    // Check if key is present at the l position
    if (t[l] == key)    
        return l; //found

    //if (counterRecursiveCalls < MAX_RECURSIVECALLS)
        return linearSearchR(t, l + 1, r, key);
    //else
        //return -1;
}

int binarySearch(int t[], int l, int r, int key)
{    
    int mid;
    while (l <= r) {
        // Find the mid
        mid = l + (r - l) / 2;

        // Check if key is present at the mid
        if (t[mid] == key)
            return mid;

        // The key lies in between l and mid 
        if (t[mid] > key)
            r = mid - 1;
        // The key lies in between mid and r
        else if (t[mid] < key)
            l = mid + 1;
    }
    // key not found
    return -1;
}

int binarySearchR(int t[], int l, int r, int key) {
    if (r >= l) {
        // Find  mid
        int mid = l + (r - l) / 2;

        // Check if key is present at the mid
        if (t[mid] == key) 
            return mid;

        // The key lies in between l and mid 
        if (t[mid] > key)
            return binarySearchR(t, l, mid - 1, key);
        // The key lies in between and mid and r
        else
            return binarySearchR(t, mid + 1, r, key);
    }
    // key not found
    return -1;
}

int ternarySearch(int t[], int l, int r, int key)
{
    int mid1, mid2;
    while (l <= r) {
        // Find  mid1 and mid2 
        int mid1 = l + (r - l) / 3;
        int mid2 = r - (r - l) / 3;

        // Check if key is present at any mid 
        if (t[mid1] == key) return mid1;
        if (t[mid2] == key) return mid2;

        // check where the key lies and iteratively repeat
        // The key lies in between l and mid1 
        if (key < t[mid1])
            r = mid1 - 1;
        // The key lies in between mid2 and r 
        else if (key > t[mid2])
            l = mid2 + 1;
        else {
            l = mid1 + 1;
            r = mid2 - 1;
        }

    }
    // key not found
    return -1;
}

int ternarySearchR(int t[], int l, int r, int key)
{
    if (r >= l) {

        // Find  mid1 and mid2 
        int mid1 = l + (r - l) / 3;
        int mid2 = r - (r - l) / 3;

        // Check if key is present at any mid 
        if (t[mid1] == key) return mid1;
        
        if (t[mid2] == key) return mid2;

        // check where the key lies and recursively repeat
        // The key lies in between l and mid1 
        if (key < t[mid1]) 
            return ternarySearchR(t, l, mid1 - 1, key);
        // The key lies in between mid2 and r 
        else if (key > t[mid2]) 
            return ternarySearchR(t, mid2 + 1, r, key);
        // The key lies in between mid1 and mid2 
        else 
            return ternarySearchR(t, mid1 + 1, mid2 - 1, key);
    }

    // Key not found 
    return -1;
}

typedef int (*searchAlgorithm)(int[], int, int, int);

typedef struct algorithm {
    string name;
    searchAlgorithm function;
};

int main()
{
    srand(123456);
    high_resolution_clock::time_point start, finish; 

    int* keys;
    createRandomArray(keys, KEYS_SIZE, MIN, MAX);
    //printArray(keys, KEYS_SIZE);
   
    int* array = NULL;

    algorithm algorithms[] = {
        {"linearSearch", &linearSearch},
        {"linearSearchR", &linearSearchR},
        {"binarySearch",&binarySearch},
        {"binarySearchR", &binarySearchR},
        {"ternarySearch", &ternarySearch},
        {"ternarySearchR", &ternarySearchR}
    };

    int algorithmsCount = sizeof(algorithms) / sizeof(algorithms[0]);
   
    //int arraySizes[] = { 1000, 2000, 3000, 4000, 5000, 6000, 7000, 8000, 9000, 10000};
    //int arraySizes[] = { 10000, 20000, 30000, 40000, 50000, 60000, 70000, 80000, 90000, 100000 };
    int arraySizes[] = { 100000, 200000, 300000, 400000, 500000, 600000, 700000, 800000, 900000, 1000000 };

    int arraySizesCount = sizeof(arraySizes) / sizeof(arraySizes[0]);


    int sizeIndex;

    duration<double>** results = new duration<double>*[algorithmsCount];
    for (int i = 0; i < algorithmsCount; i++)results[i] = new duration<double>[arraySizesCount];

    //temp var to store the position of the element we search
    int keypos = -1;

    searchAlgorithm algo;

    //repeat test for all array sizes
    for (int sizeIndex = 0; sizeIndex < arraySizesCount; sizeIndex++) {
        //initialize array with random numbers
        createRandomArray(array, arraySizes[sizeIndex], MIN, MAX);

        for (int algoIndex = 0; algoIndex < algorithmsCount; algoIndex++ ) {
            algo = algorithms[algoIndex].function;
            start = high_resolution_clock::now();
            //if(algoIndex>1) 
                qsort(array, arraySizes[sizeIndex], sizeof(int), compare);
            for (int keyIndex = 0; keyIndex < KEYS_SIZE; keyIndex++) {
                counterRecursiveCalls = 0;
                keypos = algo(array, 0, arraySizes[sizeIndex], keys[keyIndex]);
            }
            finish = high_resolution_clock::now();
            results[algoIndex][sizeIndex] = duration_cast<duration<double>>(finish - start);
        }
    }

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
    
    return -1;
}






