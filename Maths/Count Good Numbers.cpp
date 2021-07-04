// By Chandramani Kumar
// Keep moving and must be simple bro!!!!!
// Espérons le meilleur mais préparez-vous au pire 😎


/* Problem Statement :

A digit string is good if the digits (0-indexed) at even indices are even and the digits at odd indices are prime (2, 3, 5, or 7).

For example, "2582" is good because the digits (2 and 8) at even positions are even and the digits (5 and 2) at odd positions are prime. However, "3245" is not good because 3 is at an even index but is not even.
Given an integer n, return the total number of good digit strings of length n. Since the answer may be large, return it modulo 109 + 7.

A digit string is a string consisting of digits 0 through 9 that may contain leading zeros.

 
Example 1:

Input: n = 1
Output: 5

Explanation: The good numbers of length 1 are "0", "2", "4", "6", "8".

Example 2:

Input: n = 4
Output: 400

Example 3:

Input: n = 50
Output: 564908303
 

Constraints:

1 <= n <= 1015

*/


Cpp code :

class Solution {
public:
    long long int mod = 1e9 + 7;

    long long int powr(long long int n,long long int p)
    {
                if (n == 0)
                    return 0;
                if (p == 0)
                    return 1;

                long long int y;

                if (p % 2 == 0) 
                {
                    y = powr(n, p / 2);
                    y = (y * y) % mod;
                }
                else 
                {
                    y = n % mod;
                    y = (y * powr(n, p - 1) % mod) % mod;
                }
 
                return (int)((y + mod) % mod);
    }
    
    int countGoodNumbers(long long n) {
        if( n == 1 )
            return 5;
        long long int k;
        if(n%2 != 0)
            k = n/2 + 1;
        else
            k = n/2;
        
        long long int temp = powr(5,k);
        long long int l = n - k;
        long long int temp2 = powr(4,l);
        
        return (temp*temp2)%mod;
    }
};
