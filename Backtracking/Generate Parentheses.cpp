// By Chandramani Kumar
// Keep moving and must be simple bro!!!!!
// Espérons le meilleur mais préparez-vous au pire 😎


/* Problem Statement :

Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

 

Example 1:

Input: n = 3
Output: ["((()))","(()())","(())()","()(())","()()()"]

Example 2:

Input: n = 1
Output: ["()"]
 

Constraints:

1 <= n <= 8

*/


Cpp code :

class Solution {
public:
    vector<string> res;
    
    void get(string str, int r, int l)
    {
        if(l == 0 && r == 0)
        {
            res.push_back(str);
            return;
        }
        
        if(r > 0)
            get(str + "(", r-1, l+1);
        if(l > 0)
            get(str + ")", r, l-1);
    }
    
    vector<string> generateParenthesis(int n) 
    {
        get("", n, 0);
        return res;
    }

};
