// By Chandramani Kumar
// Keep moving and must be simple bro!!!!!
// Espérons le meilleur mais préparez-vous au pire 😎


/* Problem Statement :

order and str are strings composed of lowercase letters. In order, no letter occurs more than once.

order was sorted in some custom order previously. We want to permute the characters of str so that they match the order that order was sorted. More specifically, if x occurs before y in order, then x should occur before y in the returned string.

Return any permutation of str (as a string) that satisfies this property.

Example:
Input: 
order = "cba"
str = "abcd"

Output: "cbad"

Explanation: 
"a", "b", "c" appear in order, so the order of "a", "b", "c" should be "c", "b", and "a". 
Since "d" does not appear in order, it can be at any position in the returned string. "dcba", "cdba", "cbda" are also valid outputs.
 

Note:

order has length at most 26, and no character is repeated in order.
str has length at most 200.
order and str consist of lowercase letters only.

*/


Cpp code :

class Solution {
public:
    string customSortString(string order, string str) {
        string res = "";
        int n = order.size();
        int m = str.size();
        
        unordered_map<char,int> ump;
        
        int f[26] = {0};
        
        for(int i=0;i<m;i++)
            f[str[i] - 'a']++;
        
        for(int i=0;i<n;i++)
        {
            if(f[order[i] - 'a'] > 0)
            {
                ump[order[i]] = 1;
                for(int j=0;j<f[order[i] - 'a'];j++)
                    res+=order[i];
            }            
        }
        
        if(res.size() < m)
        {
            for(int i=0;i<m;i++)
            {
                if(ump[str[i]] != 1)
                    res+=str[i];
            }
        }
            
        return res;
    }
};
