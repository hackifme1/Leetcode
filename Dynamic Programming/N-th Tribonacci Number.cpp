// By Chandramani Kumar
// Keep moving and must be simple bro!!!!!
// Espérons le meilleur mais préparez-vous au pire 😎


/* Problem Statement :

The Tribonacci sequence Tn is defined as follows: 

T0 = 0, T1 = 1, T2 = 1, and Tn+3 = Tn + Tn+1 + Tn+2 for n >= 0.

Given n, return the value of Tn.

 
Example 1:

Input: n = 4
Output: 4

Explanation:
T_3 = 0 + 1 + 1 = 2
T_4 = 1 + 1 + 2 = 4


Example 2:

Input: n = 25
Output: 1389537
 

Constraints:

0 <= n <= 37
The answer is guaranteed to fit within a 32-bit integer, ie. answer <= 2^31 - 1.

*/


Cpp code :

class Solution {
public:
    int tribonacci(int n) {
        if(n == 0)
           return 0;
           
        if(n == 1 || n == 2)
           return 1;
       
        vector<int> tribo(n+1,0);
        tribo[0] = 0;
        tribo[1] = 1;
        tribo[2] = 1;
        
        for(int i=3;i<=n;i++)
        {
            tribo[i] = tribo[i-1] + tribo[i-2] + tribo[i-3]; 
        }
        
        return tribo[n];
    }
};
