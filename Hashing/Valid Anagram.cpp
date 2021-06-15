// By Chandramani Kumar
// Keep moving and must be simple bro!!!!!
// Espérons le meilleur mais préparez-vous au pire 😎


/* Problem Statement :

Given two strings s and t, return true if t is an anagram of s, and false otherwise. 

Example 1:

Input: s = "anagram", t = "nagaram"
Output: true

Example 2:

Input: s = "rat", t = "car"
Output: false
 

Constraints:

1 <= s.length, t.length <= 5 * 104
s and t consist of lowercase English letters.
 

Follow up: What if the inputs contain Unicode characters? How would you adapt your solution to such a case?

*/


Cpp code :

class Solution {
public:
    bool isAnagram(string s, string t) {
        int f_s[26]={0};
        int f_t[26]={0};
        
        for(int i=0;i<s.size();i++)
            f_s[s[i]-'a']++;
        
        for(int i=0;i<t.size();i++)
            f_t[t[i]-'a']++;
        
        for(int i=0;i<26;i++)
        {
            if(f_s[i]!=f_t[i])
                return false;
            
        }
        return true;
    }
};
