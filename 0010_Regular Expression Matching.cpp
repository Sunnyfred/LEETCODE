/*
Given an input string (s) and a pattern (p), implement regular expression matching with support for '.' and '*' where:

'.' Matches any single character.​​​​
'*' Matches zero or more of the preceding element.
The matching should cover the entire input string (not partial).



Example 1:

Input: s = "aa", p = "a"
Output: false
Explanation: "a" does not match the entire string "aa".
Example 2:

Input: s = "aa", p = "a*"
Output: true
Explanation: '*' means zero or more of the preceding element, 'a'. Therefore, by repeating 'a' once, it becomes "aa".
Example 3:

Input: s = "ab", p = ".*"
Output: true
Explanation: ".*" means "zero or more (*) of any character (.)".
Example 4:

Input: s = "aab", p = "c*a*b"
Output: true
Explanation: c can be repeated 0 times, a can be repeated 1 time. Therefore, it matches "aab".
Example 5:

Input: s = "mississippi", p = "mis*is*p*."
Output: false


Constraints:

0 <= s.length <= 20
0 <= p.length <= 30
s contains only lowercase English letters.
p contains only lowercase English letters, '.', and '*'.
*/



//Method 1: Recursion

class Solution {
public:
    bool isMatch(string s, string p)
    {
        if(p.length() == 0) return s.length()==0; // stopping criterion for recursion
        bool firstmatch = ((s.length()>0) && p[0]=='.') || (s[0] == p[0]);
        if(p.length()>=2 && p[1] == '*')
        {
            return (firstmatch && isMatch(s.substr(1), p)) || (isMatch(s, p.substr(2)));
        }
        else
        {
            return firstmatch && isMatch(s.substr(1), p.substr(1));
        }
    }
};

//Stopping criterion: check characters of string s one by one. If there is no more left in s, it should be the same for string p.if(p.length() == 0) Conduct s.length()==0;
//Need check first character of string p, use it if match. Conduct ((s.length()>0) && p[0]=='.') || (s[0] == p[0])
//For p[1]='*' (need at least 2 characters in p for sure), if first match, check s.substr(1); if first not match, discard first 2 pattern in p.
//Other cases are regular cases, check s and p one by one.



//Method 2: Dynamic Programming

class Solution {
public:
    bool isMatch(string s, string p)
    {
        int m = s.length();
        int n = p.length();
        vector<vector<bool>> dp(m+1, vector(n+1, false));
        dp[m][n] = true;

        for(int i=m; i>=0; i--)
        {
            for(int j=n-1; j>=0; j--)
            {
                bool firstmatch = (i<m && p[j] == '.') || (s[i] == p[j]);
                if(j<=n-2 && p[j+1] == '*')
                {
                    dp[i][j] = (firstmatch && dp[i+1][j]) || dp[i][j+2] ;
                }
                else
                {
                    dp[i][j] = firstmatch && dp[i+1][j+1];
                }
            }
        }
        return dp[0][0];
    }
};

// create dp array to store previous results instead of using recursion.
// here m and n in dp mean left characters in string s and p, respectively.
// if first match, i and j should start from m-1 and n-1
// Special cases is first not match, i should start from m.

