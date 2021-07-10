// By Chandramani Kumar
// Keep moving and must be simple bro!!!!!
// Espérons le meilleur mais préparez-vous au pire 😎


/* Problem Statement :

Given a binary string s and an integer k.

Return true if every binary code of length k is a substring of s. Otherwise, return false.

 
Example 1:

Input: s = "00110110", k = 2
Output: true

Explanation: The binary codes of length 2 are "00", "01", "10" and "11". They can be all found as substrings at indicies 0, 1, 3 and 2 respectively.

Example 2:

Input: s = "00110", k = 2
Output: true

Example 3:

Input: s = "0110", k = 1
Output: true

Explanation: The binary codes of length 1 are "0" and "1", it is clear that both exist as a substring. 

Example 4:

Input: s = "0110", k = 2
Output: false

Explanation: The binary code "00" is of length 2 and doesn't exist in the array.

Example 5:

Input: s = "0000000001011100", k = 4
Output: false
 

Constraints:

1 <= s.length <= 5 * 105
s[i] is either '0' or '1'.
1 <= k <= 20

*/


Cpp code :

class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int n=s.length();
        string str;
        set<string> st;
        for(int i=0;i<=(n-k);i++)
        {
            str="";
            for(int j=0;j<k;j++)
            {
               str=str+s[i+j];
            }
            st.insert(str);
        }
        if(st.size()==pow(2,k))
            return true;
        else
            return false;
    }
};
