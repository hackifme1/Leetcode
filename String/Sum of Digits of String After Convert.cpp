// By Chandramani Kumar
// Keep moving and must be simple bro!!!!!
// EspΓ©rons le meilleur mais prΓ©parez-vous au pire π


/* Problem Statement :

You are given a string s consisting of lowercase English letters, and an integer k.

First, convert s into an integer by replacing each letter with its position in the alphabet (i.e., replace 'a' with 1, 'b' with 2, ..., 'z' with 26). Then, transform the 
integer by replacing it with the sum of its digits. Repeat the transform operation k times in total.

For example, if s = "zbax" and k = 2, then the resulting integer would be 8 by the following operations:

Convert: "zbax" β "(26)(2)(1)(24)" β "262124" β 262124
Transform #1: 262124 β 2 + 6 + 2 + 1 + 2 + 4 β 17
Transform #2: 17 β 1 + 7 β 8
Return the resulting integer after performing the operations described above.

 

Example 1:

Input: s = "iiii", k = 1
Output: 36

Explanation: The operations are as follows:
- Convert: "iiii" β "(9)(9)(9)(9)" β "9999" β 9999
- Transform #1: 9999 β 9 + 9 + 9 + 9 β 36
Thus the resulting integer is 36.


Example 2:

Input: s = "leetcode", k = 2
Output: 6

Explanation: The operations are as follows:
- Convert: "leetcode" β "(12)(5)(5)(20)(3)(15)(4)(5)" β "12552031545" β 12552031545
- Transform #1: 12552031545 β 1 + 2 + 5 + 5 + 2 + 0 + 3 + 1 + 5 + 4 + 5 β 33
- Transform #2: 33 β 3 + 3 β 6
Thus the resulting integer is 6.


Example 3:

Input: s = "zbax", k = 2
Output: 8
 

Constraints:

1 <= s.length <= 100
1 <= k <= 10
s consists of lowercase English letters.

*/


Cpp code :

class Solution {
public:
    int getLucky(string s, int k) {
        int n = s.size();
        unordered_map<char,int> mp;
        
        for(int i=0;i<26;i++)
            mp[i +'a'] = i+1;
        
        string res = "";
        
        for(int i=0;i<n;i++)
        {
            res += to_string(mp[s[i]]);
        }
        
        
        int ans;
        string temp = res;
        
        while(k--)
        {
            ans = 0;
            for(int i=0;i<temp.size();i++)
            {
                ans += (temp[i] - '0');
            }
            
            temp = to_string(ans);
        }
        
        return ans;
    }
};
