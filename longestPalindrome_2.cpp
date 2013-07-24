// longestPalindrome_2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "string"
#include "iostream"

using namespace std;

string expandCenter(string s, int c1, int c2) {
//	string longest;
	int l = c1; int r = c2;
	int n = s.length();
	while (l >= 0 && r <= n - 1 && s[l] == s[r]) {
		l--;
		r++;
	}
	return s.substr(l+1, r-l-1);
}

string longestPalindrome(string s) {
	string longest = s.substr(0,1);
	int max = 1;
	int begine = 0;
	int n = s.length();
	if (n == 0) return "";
	//expand from one letter
	for (int i = 0; i < n -1; i++) {
		string tmp = expandCenter(s, i, i);
		if (tmp.length() > longest.length() ) longest = tmp;
	
		tmp = expandCenter(s, i, i+1);
		if (tmp.length() > longest.length() ) longest = tmp; 

	}
	return longest;
}
int main( )
{
	while(true) {
	cout << "please input a string:";
	string s;
	getline(cin, s);
	string palin = longestPalindrome(s);
	cout << "\n" << "the longest palindrome is: " << palin << endl;
	
	}
	return 0;
}

