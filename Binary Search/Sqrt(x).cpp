// By Chandramani Kumar
// Keep moving and must be simple bro!!!!!
// Espérons le meilleur mais préparez-vous au pire 😎


/* Problem Statement :

Given a non-negative integer x, compute and return the square root of x.

Since the return type is an integer, the decimal digits are truncated, and only the integer part of the result is returned.

Note: You are not allowed to use any built-in exponent function or operator, such as pow(x, 0.5) or x ** 0.5.

 

Example 1:

Input: x = 4
Output: 2

Example 2:

Input: x = 8
Output: 2
Explanation: The square root of 8 is 2.82842..., and since the decimal part is truncated, 2 is returned.
 

Constraints:

0 <= x <= 231 - 1

*/

Cpp code :

class Solution {
public:
    int mySqrt(int x) {
        
        long long int l=0, r = 100001;
        
        while(l<=r)
        {
            long long int m = l + (r-l)/2;
            long long int t = m*m;
            if(t == x)
                return m;
            
            if(t<x)
                l = m + 1;
            else
                r = m - 1;
        }
        if((l*l)>x)
            return l-1;
        return l;
    }
};
