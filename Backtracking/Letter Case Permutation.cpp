// By Chandramani Kumar
// Keep moving and must be simple bro!!!!!
// Espérons le meilleur mais préparez-vous au pire 😎


/* Problem Statement :

Given a string s, we can transform every letter individually to be lowercase or uppercase to create another string.

Return a list of all possible strings we could create. You can return the output in any order.

 

Example 1:

Input: s = "a1b2"
Output: ["a1b2","a1B2","A1b2","A1B2"]


Example 2:

Input: s = "3z4"
Output: ["3z4","3Z4"]


Example 3:

Input: s = "12345"
Output: ["12345"]


Example 4:

Input: s = "0"
Output: ["0"]
 

Constraints:

s will be a string with length between 1 and 12.
s will consist only of letters or digits.

*/


Cpp code :

class Solution {
public:
    vector<string> res;
    
    void letterCasePermutation_help(string &s, int indx)
    {
        if(indx >= s.size())
        {
            res.push_back(s);
            return;
        }
        
        if(isalpha(s[indx]))
        {
            if(islower(s[indx]))
            {
                s[indx] = toupper(s[indx]);
                letterCasePermutation_help(s, indx + 1);
                s[indx] = tolower(s[indx]);
                letterCasePermutation_help(s, indx + 1);
            }
            else
            {
                s[indx] = tolower(s[indx]);
                letterCasePermutation_help(s, indx + 1);
                s[indx] = toupper(s[indx]);
                letterCasePermutation_help(s, indx + 1);
            }
        }
        else
            letterCasePermutation_help(s, indx + 1);   
    }
    
    vector<string> letterCasePermutation(string s) {
        res.clear();
      
        letterCasePermutation_help(s,0);
        
        return res;
    }
};
