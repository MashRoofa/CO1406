#include <iostream>
#include "List.h"

using namespace std;

int main()
{
    List<int> list;
    list.print();

    list.insertSorted(3);
    list.insertSorted(1);
    list.insertSorted(2);
    list.insertSorted(5);
    list.insertSorted(4);
    list.print();

    cout << (list.exists(3) ? "3 exists" : "3 does not exist") << endl;
    cout << (list.exists(7) ? "7 exists" : "7 does not exist") << endl;

    list.deleteBack();
    list.print();

    list.deleteNode(2);
    list.print();
    list.deleteNode(4);
    list.print();
    list.deleteNode(1);
    list.print();
    list.deleteFront();
    list.print();
    list.deleteNode(1);

    
}
