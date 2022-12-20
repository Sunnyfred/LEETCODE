/*
Given a string s, find the length of the longest substring without repeating characters.



Example 1:

Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.
Example 2:

Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
Example 4:

Input: s = ""
Output: 0


Constraints:

0 <= s.length <= 5 * 104
s consists of English letters, digits, symbols and spaces.
*/


//Method #1: Brute Force

class Solution {
public:
    int lengthOfLongestSubstring(string s)
	{
		int len = s.length();
		int ans =0;
		for(int i=0; i<len; i++)
		{
			for(int j=i; j<len; j++)
			{
				if(!Repeated(s, i, j))
				{
					ans = max(ans, j-i+1);
				}

			}
		}
		return ans;
    }
	bool Repeated(string& s, int l, int r)
	{
		vector<int> table(128);   // ASCII table
		for(int i=l; i<=r; i++)
		{
			char c = s[i];
			table[c]++;
			if(table[c]>1)
			{
				return true;
			}
		}
		return false;
	}
};


// Method #2: Sliding Window

class Solution {
public:
    int lengthOfLongestSubstring(string s)
	{
		int len = s.length();
		int l=0, r=0, ans=0;
		vector<int> table(128);
		while(r<len)               //r is used to continue extending window
		{
			char c = s[r];
			table[c]++;
			while(table[c]>1)      //l is used to contract window if repeat is identified
			{
				char lc = s[l];
				table[lc]--;
				l++;
			}
			ans = max(ans, r-l+1);
			r++;
		}
		return ans;
    }
};


