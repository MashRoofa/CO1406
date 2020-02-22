#include <iostream>

#define MAX_SIZE 100
#include "Stack.h"
#include "Queue.h"
#include "Queue2Stacks.h"

using namespace std;

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
            // If the scanned character is an ‘)’, pop and to output string from the stack 
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

enum Direction { UP, RIGHT, DOWN, LEFT };

typedef struct Coordinates {
    int row; int col;
    Direction direction = UP;
};

bool match(Coordinates a, Coordinates b) {
    return (a.col == b.col) && (a.row == b.row);
}

void printMaze(char maze[][16], Coordinates c)
{
    printf(" ");
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 16; j++) {
            if (j == 15)
                printf("\n");
            if (i == c.row && j == c.col) cout << "c";
            else cout<< maze[i][j];
        }
    }
    printf("\n");
    // std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int main()
{
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
    

    char maze[10][16] = { "  XXXXXXXXXXXXX",
                          "X X X XXX X  XX",
                          "X             X",
                          "X X XXXXXXX X X",
                          "X X   X   X   X",
                          "X XXX  XX  XXXX",
                          "X    X X      X",
                          "XX X X X XXX XX",
                          "XX   X   X     ",
                          "XXXXXXXXXXXXXX " };

    
    Stack<Coordinates> stack;
    Coordinates current{ 0, 0};
    stack.push(current);

    while (!stack.isEmpty()) {
        
        Coordinates currentPos = stack.top();
        printMaze(maze, currentPos);

        if (currentPos.row == 9 && currentPos.col == 15) { cout << "Path Found!" << endl; return -1; }
        
        if (maze[currentPos.row + 1][currentPos.col]==' ' && !match(currentPos, Coordinates{ currentPos.row + 1, currentPos.col}))
            stack.push(Coordinates{ currentPos.row + 1, currentPos.col});
        else if (maze[currentPos.row][currentPos.col+1] == ' ' && !match(currentPos, Coordinates{ currentPos.row, currentPos.col+1}))
            stack.push(Coordinates{ currentPos.row, currentPos.col + 1});
        else if (maze[currentPos.row-1][currentPos.col] == ' ' && !match(currentPos, Coordinates{ currentPos.row -1, currentPos.col}))
            stack.push(Coordinates{ currentPos.row - 1, currentPos.col});
        else if (maze[currentPos.row][currentPos.col - 1] == ' ' && !match(currentPos, Coordinates{ currentPos.row, currentPos.col-1}))
            stack.push(Coordinates{ currentPos.row, currentPos.col - 1,});
        else {
            //deadend
            maze[currentPos.row][currentPos.col] = 'X';            
            stack.pop();
            continue;
        }

    }

    cout << "Path NOT found!" << endl;


}
