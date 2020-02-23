#include <iostream>
#include <fstream>
#include <string>

#define MAX_SIZE 100
#include "Stack.h"
#include "Queue.h"
#include "Queue2Stacks.h"

using namespace std;

void int2Binary(unsigned int x) {
    Stack<int> stack;
    
    while (x > 1) {
        stack.push(x % 2);
        x = x / 2;
    }
    stack.push(x);

    while (!stack.isEmpty()) {
        cout<< stack.top();
        stack.pop();
    }
}




bool match(char a, char b) {
    return ((a == '(' && b == ')') || 
            (a == '{' && b == '}') || 
            (a == '[' && b == ']'));
}

bool isBalanced(string statement) {
    Stack<char> stack;

    for (char c : statement) {
        if (! (c == '(' || 
               c == '[' || 
               c == '{' || 
               c == '}' || 
               c == ']' || 
               c == ')' )
            ) continue;

        if (c == '(' || 
            c == '[' || 
            c == '{') 
            stack.push(c); 
        else {
            if (stack.isEmpty()) return false;
            if (!match(stack.top(), c) ) return false;
            else stack.pop();
        }
    }
    return true;
}




int opPrecedence(char c)
{
    if (c == '^')
        return 3;
    else if (c == '*' || c == '/')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}

string reversePolishNotation(string s)
{
    string result;

    Stack<char> stack;
    
    for (char c: s)
    {
        //ignore whitespaces
        if (isspace(c)) continue;

        //add identifiers to output
        else if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
            result += c;

        //push left parenthesis to the stack. 
        else if (c == '(')
            stack.push(c);

        else if (c == ')')
        {
            // If the scanned character is an ‘)’, pop everything to output string from the stack 
            // until an ‘(‘ is encountered. 
            while (stack.top() != '(')
            {
                result += stack.top();
                stack.pop();
            }

            if (stack.top() == '(')
                stack.pop();
        }
        //If an operator is scanned 
        else {
            while (opPrecedence(c) <= opPrecedence(stack.top()))
            {
                result+= stack.top();
                stack.pop();
            }
            stack.push(c);
        }

    }
    //Pop all the remaining elements from the stack 
    while (!stack.isEmpty())
    {
        result += stack.top();
        stack.pop();
    }

    return result;

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
    return (a.row==b.row && a.col==b.col);
}

void printMaze(int** maze, int rows, int columns) {
    /*
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            cout<< maze[i][j];
        }
        cout << endl;
    }
    */
    for (int i = rows-1; i >= 0; i--) {
        for (int j = 0; j < columns; j++) {
            cout << maze[i][j];
        }
        cout << endl;
    }
    cout << endl;
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
    problem->start.direction = 'F';

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

void printStackReverse(Stack<Coordinates> s) {
    if (!s.isEmpty()) {
        char direction = s.top().direction;
        s.pop();
        printStackReverse(s);
        cout << direction << " ";
    }
}

void solveMaze(MazeProblem* problem, bool debug = false) {
    printMaze(problem->maze, problem->rows, problem->columns);

    Stack<Coordinates> stack;
    //Coordinates start{ problem->start.row, problem->start.col, 'S' };
    //Coordinates finish{ problem->finish.row, problem->finish.col, 'F' };
    stack.push(problem->start);

    while (!stack.isEmpty()) {

        Coordinates currentPos = stack.top();
        problem->maze[currentPos.row][currentPos.col] = 2;//visited
        if(debug) printMaze(problem->maze, problem->rows, problem->columns);

        if (match(currentPos, problem->finish)) {
            cout << "Path Found!" << endl;
            printStackReverse(stack);
            cout << "\n\n" << endl;
            return ;
        }

        if ((currentPos.row + 1 < problem->rows) && problem->maze[currentPos.row + 1][currentPos.col] == 1)
            stack.push(Coordinates{ currentPos.row + 1, currentPos.col, 'U' });
        else if ((currentPos.col + 1 < problem->columns) && problem->maze[currentPos.row][currentPos.col + 1] == 1)
            stack.push(Coordinates{ currentPos.row, currentPos.col + 1, 'R' });
        else if ((currentPos.row - 1 >= 0) && problem->maze[currentPos.row - 1][currentPos.col] == 1)
            stack.push(Coordinates{ currentPos.row - 1, currentPos.col, 'D' });
        else if ((currentPos.col - 1 >= 0) && problem->maze[currentPos.row][currentPos.col - 1] == 1)
            stack.push(Coordinates{ currentPos.row, currentPos.col - 1, 'L' });
        else {
            //dead end
            problem->maze[currentPos.row][currentPos.col] = 0;
            stack.pop();
            continue;
        }

    }

    cout << "Path NOT found!" << endl;
}

int main()
{
   
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
    
    MazeProblem* problem;
    
    problem = loadMaze("maze6_6.dat");
    solveMaze(problem);
    
    problem = loadMaze("maze6_7.dat");
    solveMaze(problem);

    problem = loadMaze("maze10_16.dat");
    solveMaze(problem);
    

}
