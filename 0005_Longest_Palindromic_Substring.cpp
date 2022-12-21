/*
Given a string s, return the longest palindromic substring in s.



Example 1:

Input: s = "babad"
Output: "bab"
Note: "aba" is also a valid answer.
Example 2:

Input: s = "cbbd"
Output: "bb"
Example 3:

Input: s = "a"
Output: "a"
Example 4:

Input: s = "ac"
Output: "a"


Constraints:

1 <= s.length <= 1000
s consist of only digits and English letters (lower-case and/or upper-case),
*/


// Method #1: Brute Force

class Solution {
public:
    string longestPalindrome(string s)
    {
        int len = s.length();
        int index = 0;
        int max_len = 0;
        for(int i=0; i<len; i++)
        {
            for(int j=i; j<len; j++)
            {
                if(IsPalindrome(s, i, j))
                {
                    if(j-i+1 > max_len)
                    {
                        max_len = j-i+1;
                        index = i;
                    }
                }
            }
        }
        return s.substr(index, max_len);
    }
    bool IsPalindrome(string s, int i, int j)
    {
        while(i<=j)
        {
            if(s[i]!=s[j])
            {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
};

//Method #2: Dynamic Programming

class Solution {
public:
    string longestPalindrome(string s)
    {
        int len = s.length();
        int index = 0;
        int max_len = 0;
        vector<vector<int>> dp(len, vector<int>(len, -1)); // initialized dp array
        for(int i=len-1; i>=0; i--)
        {
            for(int j=i; j<len; j++)
            {
                if(i==j)
                {
                    dp[i][j] = 1;
                }
                else if(s[i]==s[j])
                {
                    if(j-i==1) dp[i][j] = 1;
                    else dp[i][j] = dp[i+1][j-1];
                }
                if(dp[i][j]==1)
                {
                    if(j-i+1>max_len)
                    {
                        max_len = j-i+1;
                        index = i;
                    }
                }
            }
        }
        return s.substr(index, max_len);
    }
};

//dp array is used to store states (1: Palindrome, -1: not Palindrome) of string from index i to j.
//case 1: single character. i=j, dp[i][j]=1 for sure.
//case 2: two characters. j=i-1, if s[i] = s[j], dp[i][j]=1.
//case 3: more than 2 characters. j-i>=2, if s[i] = s[j], dp[i][j] = dp[i+1][j-1]
//current index i need i+1, so i should range from len-1 to 0.
//current index j meed j-1 and we should first consider case 1, then case 2 and 3, so j range from i to len-1.
