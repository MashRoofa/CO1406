#include <iostream>
#include <fstream>
#include <string>
#define MAX_SIZE 100
#include "Stack.h"
#include "Queue.h"
//#include "Queue2Stacks.h"

using namespace std;

void int2Binary(unsigned int x) {
    
}

bool match(char a, char b) {
    return ((a == '(' && b == ')') ||
        (a == '{' && b == '}') ||
        (a == '[' && b == ']'));
}

bool isBalanced(string statement) {
   return true;
}

string reversePolishNotation(string s)
{
    return "";
}

typedef struct Coordinates {
    int row; int col;
    char direction = 'U';
};

typedef struct MazeProblem {
    int** maze;
    int rows;
    int columns;
    Coordinates start;
    Coordinates finish;
};

bool match(Coordinates& a, Coordinates& b) {
    return (a.row == b.row && a.col == b.col);
}

void printMaze(int** maze, int rows, int columns) {

}

MazeProblem* loadMaze(string filename) {
    MazeProblem* problem = new MazeProblem();

    ifstream file(filename);

    file >> problem->rows;
    file >> problem->columns;

    file >> problem->start.row;
    file >> problem->start.col;
    problem->start.direction = 'S';

    file >> problem->finish.row;
    file >> problem->finish.col;
    problem->finish.direction = 'F';

    problem->maze = new int* [problem->rows];
    for (int i = 0; i < problem->rows; i++) {
        problem->maze[i] = new int[problem->columns];
    }
    for (int i = 0; i < problem->rows; i++) {
        for (int j = 0; j < problem->columns; j++) {
            file >> problem->maze[i][j];
        }
    }
    return problem;
}

void solveMaze(MazeProblem* problem, bool debug = false) {
    
}

int main()
{
    //Uncomment the sections you want to check

    /*
    cout << 8 << " to binary is "; int2Binary(8); cout << endl;
    cout << 11 << " to binary is "; int2Binary(11); cout << endl;
    cout << 13 << " to binary is "; int2Binary(13); cout << endl;
    cout << 17 << " to binary is "; int2Binary(17); cout << endl;
    */

    /*
    string test1 = "{ [ ] }";
    string test2 = "( [ { } { } [ ] ) )";
    string test3 = "( [ ] { ( ) } )";

    std::cout << test1 << " is " << (isBalanced(test1) ? "" : " NOT ") << " balanced\n";
    std::cout << test2 << " is " << (isBalanced(test2) ? "" : " NOT ") << " balanced\n";
    std::cout << test3 << " is " << (isBalanced(test3) ? "" : " NOT ") << " balanced\n";
    */

    /*
    Queue2Stacks<int> queue2stacks;
    for (int i = 1; i <=5; i++) {
        queue2stacks.enqueue(i);
    }
    cout<<queue2stacks.dequeue()<<endl;
    queue2stacks.enqueue(6);

    for (int i = 1; i <= 6; i++) {
        cout << queue2stacks.dequeue() << endl;
    }
    */

    /*
    string test1 = "a + b";                 //ab+
    string test2 = "(a + b)*c";             //ab+c*
    string test3 = "a + (b*c)";             //abc*+
    string test4 = "a*b + c*d";             //ab*cd*+
    string test5 = "a - ((b+c) * (d+e))";   //abc+de+*-
    string test6 = "a+b*(c^d-e)^(f+g*h)-i"; //abcd^e-fgh*+^*+i-

    cout.width(50); cout << left << test1 << right << reversePolishNotation(test1) << "\n";
    cout.width(50); cout << left << test2 << right << reversePolishNotation(test2) << "\n";
    cout.width(50); cout << left << test3 << right << reversePolishNotation(test3) << "\n";
    cout.width(50); cout << left << test4 << right << reversePolishNotation(test4) << "\n";
    cout.width(50); cout << left << test5 << right << reversePolishNotation(test5) << "\n";
    cout.width(50); cout << left << test6 << right << reversePolishNotation(test6) << "\n";
    */

    /*
    MazeProblem* problem;

    problem = loadMaze("maze6_6.dat");
    solveMaze(problem);

    problem = loadMaze("maze6_7.dat");
    solveMaze(problem);

    problem = loadMaze("maze10_16.dat");
    solveMaze(problem);
    */

}
