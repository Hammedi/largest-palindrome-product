// Author: Abraham Medina
// Last Modified: 11/26/2014

#include <iostream>
#include <string>
#include <stack>
#include <queue>
using namespace std;

bool isPalindrome(int); // Checks if an int is a palindrome

int main()
{
	int largestPalindrome = 0;
	
	for(int i = 100; i < 1000; i++) // Increments i
	{
		for(int x = 100; x < 1000; x++) // Increments x
		{
			// Checks if product of i and x is a palindrom
			if(isPalindrome(i * x) && i * x > largestPalindrome)
			{
				largestPalindrome = i * x;
			}
		}
	}
	
	cout << "Largest Palindrome: " << largestPalindrome << endl;
	
	return 0;
}

bool isPalindrome(int value)
{
	int size = to_string(value).length(); // Saves length of value
	stack<int> myStack;
	queue<int> myQueue;
	
	for(int i = 0; i < size; i++) // Disassembles value into stack and queue
	{
		myStack.push(value % 10);
		myQueue.push(value % 10);
		value /= 10;
	}
	
	for(int i = 0; i < size; i++) // Compares the elemts of stack and queue
	{
		if(myStack.top() != myQueue.front())
		{
			return false; // false if value is not palindrome
		}
		myStack.pop();
		myQueue.pop();
	}
	
	return true; // true if value is a palindrome
}
