#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>

using namespace std;

int mpower(int a, int n) {
	if (n == 0) return 1;
	return a * mpower(a, n - 1);
}

int fibonacci(unsigned int n) {
	return (n <= 1) ? n : fibonacci(n - 1) + fibonacci(n - 2);
}

bool isPalindrome(string s) {
	if (s.size() <= 1)
		return true;

	else if (s.at(0) != s.at(s.size() - 1))
		return false;

	else
		return isPalindrome(s.substr(1, s.size() - 2));
}

bool isPalindrome(const string& s, int low, int high) {
	if (low>=high)
		return true;
	else if (s.at(low) != s.at(high))
		return false;
	else
		return isPalindrome(s, low+1, high-1);
}

void hanoi(int n, char towerA, char towerB, char towerC) {
	if (n == 1) // Base condition
		cout << "Move disk " << n << " from " << towerA << " to " << towerB << "\n";
	else {
		//Step 1: Recursively move the first n-1 disks from A to C
		hanoi(n - 1, towerA, towerC, towerB);

		//Step 2: Move nth disk from A to B
		cout << "Move disk " << n << " from " << towerA << " to " << towerB << "\n";

		//Step 3: Move the n - 1 disks from C to B
		hanoi(n - 1, towerC, towerB, towerA);
	}
}

int binarySearch(int t[], int l, int r, int key)
{
	if (r >= l) {
		int mid = l + (r - l) / 2;

		if (t[mid] == key) return mid;

		if (t[mid] > key) return binarySearch(t, l, mid - 1, key);
		
		return binarySearch(t, mid + 1, r, key);
	}
	return -1;
}

int main()
{
	/*
	string s;
	s = "";
	cout << s<< ":" << boolalpha << isPalindrome(s) << "\n";
	s = "aba";
	cout << s << ":" << boolalpha << isPalindrome(s) << "\n";
	s = "abba";
	cout << s << ":" << boolalpha << isPalindrome(s) << "\n";
	s = "abca";
	cout << s << ":" << boolalpha << isPalindrome(s) << "\n";
	s = "abcba";
	cout << s << ":" << boolalpha << isPalindrome(s) << "\n";
	s = "abbca";
	cout << s << ":" << boolalpha << isPalindrome(s) << "\n";
	*/

	/*
	cout << "\n\nPalindromes\n";
	string s;
	s = "";
	cout << s << ":" << boolalpha << isPalindrome(s, 0, s.size()-1) << "\n";
	s = "aba";
	cout << s << ":" << boolalpha << isPalindrome(s, 0, s.size() - 1) << "\n";
	s = "abba";
	cout << s << ":" << boolalpha << isPalindrome(s, 0, s.size() - 1) << "\n";
	s = "abca";
	cout << s << ":" << boolalpha << isPalindrome(s, 0, s.size() - 1) << "\n";
	s = "abcba";
	cout << s << ":" << boolalpha << isPalindrome(s, 0, s.size() - 1) << "\n";
	s = "abbca";
	cout << s << ":" << boolalpha << isPalindrome(s, 0, s.size() - 1) << "\n";
	*/

	//cout << "\n\nHanoi Towers\n"; 
	//hanoi(8, 'A', 'B', 'C');

	

}
