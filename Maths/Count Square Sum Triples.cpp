// By Chandramani Kumar
// Keep moving and must be simple bro!!!!!
// Espérons le meilleur mais préparez-vous au pire 😎


/* Problem Statement :

A square triple (a,b,c) is a triple where a, b, and c are integers and a2 + b2 = c2.

Given an integer n, return the number of square triples such that 1 <= a, b, c <= n.


Example 1:

Input: n = 5
Output: 2

Explanation: The square triples are (3,4,5) and (4,3,5).

Example 2:

Input: n = 10
Output: 4

Explanation: The square triples are (3,4,5), (4,3,5), (6,8,10), and (8,6,10).
 

Constraints:

1 <= n <= 250

*/


Cpp code :

class Solution {
public:
    int countTriples(int n) {
        int cnt = 0;
        
        for(int i=1;i<=n;i++)
        {
            for(int j=i;j<=n;j++)
            {
                int temp = i*i + j*j;
                int c = sqrt(temp);
                
                if(c*c == temp && c <= n)
                    ++cnt;
            }
        }
        
        return 2*cnt;
    }
};
