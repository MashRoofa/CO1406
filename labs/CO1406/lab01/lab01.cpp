// lab01.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <ctime>
#include <cstdlib>

#define SIZE 10000

#define MIN 0
#define MAX 10000

#define REPETITIONS 100

using namespace std;

int compare(const void* a, const void* b)
{
    return (*(int*)a - *(int*)b);
}

int linearSearch(int t[], int n, int key)
{
    for (int i = 0; i < n; i++)
        if (t[i] == key) return i;
    return -1;
}

int binarySearch(int t[], int l, int r, int key)
{
    if (r >= l) {
        int mid = l + (r - l) / 2;

        if (t[mid] == key)
            return mid;

        if (t[mid] > key)
            return binarySearch(t, l, mid - 1, key);

        return binarySearch(t, mid + 1, r, key);
    }

    return -1;
}

int random(int min, int max) {
    return min + int((max-min+1) * rand() / (RAND_MAX + 1.0));
}

void createRandomArray(int t[], int n, int l, int h) {
    for (int i = 0; i < n; i++) {
        t[i] = random(l, h);
    }
}


int main()
{
    srand(123456);
    clock_t start, finish;
    double  durationLinear=0, durationBinary=0;

    int array[SIZE];

    int keys[SIZE];
    createRandomArray(keys, SIZE, MIN, MAX);

    int keypos = -1;

    for (int i = 0; i < REPETITIONS; i++) {
        createRandomArray(array, SIZE, MIN, MAX);

        //linear search
        start = clock();
        for (int j = 0; j < SIZE; j++) {
            keypos = linearSearch(array, SIZE, keys[j]);
        }
        finish = clock();
        durationLinear += (double)(finish - start) / CLOCKS_PER_SEC;

        //binary search
        start = clock();
        qsort(array, SIZE, sizeof(int), compare);
        for (int j = 0; j < SIZE; j++) {
            keypos = binarySearch(array, 0, SIZE-1, keys[j]);
        }
        finish = clock();
        durationBinary += (double)(finish - start) / CLOCKS_PER_SEC;
    }
    
    cout << "Benchmark results" << endl;
    cout << "Duration Linear:" << durationLinear/REPETITIONS << endl;
    cout << "Duration Binary:" << durationBinary/ REPETITIONS << endl;

}



void printArray(int t[], int n) {
    for (int i = 0; i < n; i++) {
        cout << t[i] << " ";
    }
    cout << endl;
}


