// By Chandramani Kumar
// Keep moving and must be simple bro!!!!!
// Espérons le meilleur mais préparez-vous au pire 😎


/* Problem Statement :

Given a string s and a dictionary of strings wordDict, return true if s can be segmented into a space-separated sequence of one or more dictionary words.

Note that the same word in the dictionary may be reused multiple times in the segmentation.

 

Example 1:

Input: s = "leetcode", wordDict = ["leet","code"]
Output: true

Explanation: Return true because "leetcode" can be segmented as "leet code".

Example 2:

Input: s = "applepenapple", wordDict = ["apple","pen"]
Output: true

Explanation: Return true because "applepenapple" can be segmented as "apple pen apple".

Note that you are allowed to reuse a dictionary word.

Example 3:

Input: s = "catsandog", wordDict = ["cats","dog","sand","and","cat"]
Output: false
 

Constraints:

1 <= s.length <= 300
1 <= wordDict.length <= 1000
1 <= wordDict[i].length <= 20
s and wordDict[i] consist of only lowercase English letters.
All the strings of wordDict are unique.

*/


Cpp code :

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        vector<bool> dp(n,0);
        unordered_map<string,int> hash;
        
        for(int i=0;i<wordDict.size();i++)
            hash[wordDict[i]] = 1;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<=i;j++)
            {
                string str = s.substr(j,i-j+1);
                
                if(hash[str] == 1)
                {
                    if(j > 0)
                        dp[i] = dp[i] | dp[j - 1];
                    else
                        dp[i] = true;
                }                
            }
        }

        return dp[n-1];
    }
};
