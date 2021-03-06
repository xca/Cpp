// longestPalindrome_1.cpp 
// use dynamic programming to detect the longest palindrome substring given a string

#include "stdafx.h"
#include "string"
#include "iostream"

using namespace std;

string longestPalindromeDP(string s) {
	int n = s.length();
	int begin = 0;
	int max = 1;
	bool table[1000][1000] = {false};
	for (int i = 0; i < n; i++) {
		table[i][i] = true; //every single letter is a palindrome
	}
	for (int i = 0; i < n-1; i++) {
		if (s[i] == s[i+1]) {
			table[i][i+1] = true;
			begin = i;
			max = 2; // the neighbor two are the same
		}
	}
	for (int len = 3; len <= n; len++) {
		for (int i = 0; i < n-len+1; i++) {
			int j = i+len-1;
			if (s[i] == s[j] && table[i+1][j-1]) {
				table[i][j] = true;
				begin = i;
				max = len;
			}
//			cout << "i: " <<i<<"\tj:"<<j<<"\ts[i]: "<<s[i]<<"\ts[j]: "<<s[j]<<endl;
		}
	}
	return s.substr(begin, max);
}

int main()
{
	while (true) {
		cout << "please input a string:";
		string s;
		getline(cin, s);
		string palin = longestPalindromeDP(s);
		cout << "the longest palindrome is: " << palin << endl;
	}
	return 0;
}

