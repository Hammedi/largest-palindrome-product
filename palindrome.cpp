#include <iostream>
#include <string>
#include <stack>
#include <queue>
using namespace std;

bool isPalindrome(int);

int main()
{
	int largestPalindrome = 0;
	
	for(int i = 100; i < 1000; i++)
	{
		for(int x = 100; x < 1000; x++)
		{
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
	int size = to_string(value).length();
	stack<int> myStack;
	queue<int> myQueue;
	
	for(int i = 0; i < size; i++)
	{
		myStack.push(value % 10);
		myQueue.push(value % 10);
		value /= 10;
	}
	
	for(int i = 0; i < size; i++)
	{
		if(myStack.top() != myQueue.front())
		{
			return false;
		}
		myStack.pop();
		myQueue.pop();
	}
	
	return true;
}
