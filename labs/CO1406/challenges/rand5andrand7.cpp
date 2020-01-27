// challenges.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

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

int main()
{
    srand(time(NULL));

    int panic[7] = { 0,0,0,0,0,0,0 };
    int pampots[7] = { 0,0,0,0,0,0,0 };

    int array[5][5] = {
                        1,2,3,4,5,
                        6,7,1,2,3,
                        4,5,6,7,1,
                        2,3,4,5,6,
                        7,0,0,0,0
                    };

    int r1, r2,  sum;

    for (int i = 0; i < 10000; i++) {
        
        r1 = 5, r2 = 5;
        while (array[r1 - 1][r2 - 1] == 0)
        {
            r1 = random(1, 5);
            r2 = random(1, 5);
        }
        panic[array[r1-1][r2-1] - 1]++;


        sum = 0;
        pampots[(random(1, 5) + random(1, 5) + random(1, 5) + random(1, 5) + random(1, 5) + random(1, 5) + random(1, 5)) % 7] ++;
        
    }

    printArray(panic, 7);

    printArray(pampots, 7);

    return 0;

}
