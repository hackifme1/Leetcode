// By Chandramani Kumar
// Keep moving and must be simple bro!!!!!
// Espérons le meilleur mais préparez-vous au pire 😎


/* Problem Statement :

Given two strings s and part, perform the following operation on s until all occurrences of the substring part are removed:

Find the leftmost occurrence of the substring part and remove it from s.
Return s after removing all occurrences of part.

A substring is a contiguous sequence of characters in a string.
 

Example 1:

Input: s = "daabcbaabcbc", part = "abc"
Output: "dab"

Explanation: The following operations are done:
- s = "daabcbaabcbc", remove "abc" starting at index 2, so s = "dabaabcbc".
- s = "dabaabcbc", remove "abc" starting at index 4, so s = "dababc".
- s = "dababc", remove "abc" starting at index 3, so s = "dab".
Now s has no occurrences of "abc".

Example 2:

Input: s = "axxxxyyyyb", part = "xy"
Output: "ab"

Explanation: The following operations are done:
- s = "axxxxyyyyb", remove "xy" starting at index 4 so s = "axxxyyyb".
- s = "axxxyyyb", remove "xy" starting at index 3 so s = "axxyyb".
- s = "axxyyb", remove "xy" starting at index 2 so s = "axyb".
- s = "axyb", remove "xy" starting at index 1 so s = "ab".
Now s has no occurrences of "xy".
 

Constraints:

1 <= s.length <= 1000
1 <= part.length <= 1000
s and part consists of lowercase English letters.

*/


Cpp code :

class Solution {
public:
    string removeOccurrences(string s, string part) {
        stack<char> stck;
        int N = s.size();
        int M = part.size();
        for (int i = 0; i < N; i++) 
        {    
            stck.push(s[i]);
    
            if (stck.size() >= M) 
            {
                string l = "";
    
                for (int j = M - 1; j >= 0; j--) 
                {
                    if (part[j] != stck.top())
                    {
                        int f = 0;
                        while (f != l.size()) 
                        {    
                            stck.push(l[f]);
                            f++;
                        }
    
                        break;
                    }
                    else 
                    {    
                        l = stck.top() + l;
                        stck.pop();
                    }
                }
            }
        }
        
        string res="";
        
        while(!stck.empty())
        {
            res+=stck.top();
            stck.pop();
        }
        
        reverse(res.begin(),res.end());
        
        return res;
    }
};
