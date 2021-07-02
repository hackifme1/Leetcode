// By Chandramani Kumar
// Keep moving and must be simple bro!!!!!
// Espérons le meilleur mais préparez-vous au pire 😎


/* Problem Statement :

An n-bit gray code sequence is a sequence of 2n integers where:

Every integer is in the inclusive range [0, 2n - 1],
The first integer is 0,
An integer appears no more than once in the sequence,
The binary representation of every pair of adjacent integers differs by exactly one bit, and
The binary representation of the first and last integers differs by exactly one bit.
Given an integer n, return any valid n-bit gray code sequence.

 

Example 1:

Input: n = 2
Output: [0,1,3,2]

Explanation:
The binary representation of [0,1,3,2] is [00,01,11,10].
- 00 and 01 differ by one bit
- 01 and 11 differ by one bit
- 11 and 10 differ by one bit
- 10 and 00 differ by one bit
[0,2,3,1] is also a valid gray code sequence, whose binary representation is [00,10,11,01].
- 00 and 10 differ by one bit
- 10 and 11 differ by one bit
- 11 and 01 differ by one bit
- 01 and 00 differ by one bit

Example 2:

Input: n = 1
Output: [0,1]
 

Constraints:

1 <= n <= 16

*/


Cpp code :

class Solution {
public:
    int binaryToDecimal(string n)
    {
        int val = 0;

        int temp = 1;

        int sz = n.size();
        
        for (int i = sz - 1; i >= 0; i--) 
        {
            if (n[i] == '1')
                val += temp;
            temp = temp * 2;
        }

        return val;
    }
    
    vector<int> grayCode(int n) {
        vector<string> ans;
        vector<int> res;      
        if (n <= 0)
            return res;

        ans.push_back("0");
        ans.push_back("1");

        int i, j;

        for (i = 2; i < (1<<n); i = i<<1)
        {
            for (j = i-1 ; j >= 0 ; j--)
                ans.push_back(ans[j]);

            for (j = 0 ; j < i ; j++)
                ans[j] = "0" + ans[j];

            for (j = i ; j < 2*i ; j++)
                ans[j] = "1" + ans[j];
        }

        for(int i=0;i<ans.size();i++)
        res.push_back(binaryToDecimal(ans[i]));
        
        return res;
    }
};
