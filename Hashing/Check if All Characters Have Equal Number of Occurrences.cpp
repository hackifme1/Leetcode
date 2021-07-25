// By Chandramani Kumar
// Keep moving and must be simple bro!!!!!
// Espérons le meilleur mais préparez-vous au pire 😎


/* Problem Statement :

Given a string s, return true if s is a good string, or false otherwise.

A string s is good if all the characters that appear in s have the same number of occurrences (i.e., the same frequency).


Example 1:

Input: s = "abacbc"
Output: true

Explanation: The characters that appear in s are 'a', 'b', and 'c'. All characters occur 2 times in s.


Example 2:

Input: s = "aaabb"
Output: false

Explanation: The characters that appear in s are 'a' and 'b'.
'a' occurs 3 times while 'b' occurs 2 times, which is not the same number of times.
 

Constraints:

1 <= s.length <= 1000
s consists of lowercase English letters.

*/


Cpp code :

class Solution {
public:
    bool areOccurrencesEqual(string s) {
        int f[26] = {0};
        int n = s.size();
        
        for(int i=0;i<n;i++)
        {
            f[s[i]-'a']++;
        }
        
        int chk = 0;
        
        for(int i=0;i<26;i++)
        {
            if(f[i])
            {
                chk = f[i];
            }
        }
        
        for(int i=0;i<26;i++)
        {
            if(f[i] && f[i] != chk)
                return false;
        }
        
        return true;
    }
};
