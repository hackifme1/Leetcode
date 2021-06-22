// By Chandramani Kumar
// Keep moving and must be simple bro!!!!!
// Espérons le meilleur mais préparez-vous au pire 😎


/* Problem Statement :

Given a string s and an array of strings words, return the number of words[i] that is a subsequence of s.

A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.

For example, "ace" is a subsequence of "abcde".
 

Example 1:

Input: s = "abcde", words = ["a","bb","acd","ace"]
Output: 3
Explanation: There are three strings in words that are a subsequence of s: "a", "acd", "ace".

Example 2:

Input: s = "dsahjpjauf", words = ["ahjpjau","ja","ahbwzgqnuk","tnmlanowax"]
Output: 2
 

Constraints:

1 <= s.length <= 5 * 104
1 <= words.length <= 5000
1 <= words[i].length <= 50
s and words[i] consist of only lowercase English letters.

*/


Cpp code :

class Solution {
public:
    bool issubsq(string str,string str1)
    {
        int m = str.size();
        int n = str1.size();
        
        if(str1==str)
            return true;
        
         int j = 0; 
        
        for (int i = 0; i < n && j < m; i++)
        {
            if (str[j] == str1[i])
                j++;
        }

        return (j == m);
    }
        
    int numMatchingSubseq(string s, vector<string>& words) {
        
        int n = words.size();
        int cnt = 0;
        
        unordered_map<string,int> ump;
        
        for(int i=0;i<n;i++)
        {
            ump[words[i]]++;
        }
        
        for(auto itr=ump.begin();itr!=ump.end();itr++)
        {
            if(issubsq(itr->first,s))
                cnt=cnt+itr->second;
        }
        
        return cnt;
    }
};
