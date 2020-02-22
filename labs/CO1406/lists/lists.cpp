#include <iostream>
#include "List.h"

using namespace std;

int main()
{
    List<int> list;
    list.insertSorted(3);
    list.print();
    list.insertSorted(1);
    list.print();
    list.insertSorted(2);
    list.print();
    list.insertSorted(5);
    list.print();
    list.insertSorted(4);
    list.print();

    std::cout << "Hello World!\n";
}
