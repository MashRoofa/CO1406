#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int random(int min, int max) {
    return min + int((max - min + 1) * rand() / (RAND_MAX + 1.0));
}

void printArray(int t[], int n) {
    for (int i = 0; i < n; i++) {
        cout << t[i] << " ";
    }
    cout << endl;
}

int linearSearch(int t[], int n, int key)
{
    for (int i = 0; i < n; i++)
        if (t[i] == key) return i;
    return -1;
}

int compare(const void* a, const void* b)
{
    return (*(int*)a - *(int*)b);
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


int main()
{
    srand(100);
    int array[100];
    for (int i = 0; i < 100; i++) {
        array[i] = random(0, 100);
    }
    printArray(array, 100);
    cout << "The position of 34 is " << linearSearch(array, 100, 34) << endl;
    cout << "The position of 99 is " << linearSearch(array, 100, 99)<<endl;

    qsort(array, 100, sizeof(int), compare);
    cout << "The position of 34 is " << binarySearch(array, 0, 100, 34) << endl;
    cout << "The position of 99 is " << binarySearch(array, 0, 100, 99) << endl;
}
