// By Chandramani Kumar
// Keep moving and must be simple bro!!!!!
// Espérons le meilleur mais préparez-vous au pire 😎


/* Problem Statement :

Given two strings s and t, determine if they are isomorphic.

Two strings s and t are isomorphic if the characters in s can be replaced to get t.

All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character, but a character may map to itself.


Example 1:

Input: s = "egg", t = "add"
Output: true

Example 2:

Input: s = "foo", t = "bar"
Output: false

Example 3:

Input: s = "paper", t = "title"
Output: true
 

Constraints:

1 <= s.length <= 5 * 104
t.length == s.length
s and t consist of any valid ascii character.

*/


Cpp code :

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int n = s.size();

        int freq_s[256] = {0}, freq_t[256] = {0};
        
        for (int i = 0; i < n; ++i) 
        {
            if (freq_s[s[i]] != freq_t[t[i]])
                return false;
            
            freq_s[s[i]] = i + 1;
            freq_t[t[i]] = i + 1;
        }
        
        return true;
    }
};
