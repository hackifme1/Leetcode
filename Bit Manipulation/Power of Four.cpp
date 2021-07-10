// By Chandramani Kumar
// Keep moving and must be simple bro!!!!!
// Espérons le meilleur mais préparez-vous au pire 😎


/* Problem Statement :

Given an integer n, return true if it is a power of four. Otherwise, return false.

An integer n is a power of four, if there exists an integer x such that n == 4x.

 
Example 1:

Input: n = 16
Output: true

Example 2:

Input: n = 5
Output: false

Example 3:

Input: n = 1
Output: true
 

Constraints:

-231 <= n <= 231 - 1

*/


Cpp code :

class Solution {
public:
    bool isPowerOfFour(int num) {
        
            
        if(num<=0)
            return false;
        else{
            int f=floor(log2(abs(num)))+1;

                if((f&1)&&!(num&(num-1)))
                    return true;
                else
                    return false;
        }
    }
};
