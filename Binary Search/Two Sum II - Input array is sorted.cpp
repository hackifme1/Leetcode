// By Chandramani Kumar
// Keep moving and must be simple bro!!!!!
// Espérons le meilleur mais préparez-vous au pire 😎


/* Problem Statement

Given an array of integers numbers that is already sorted in non-decreasing order, find two numbers such that they add up to a specific target number.

Return the indices of the two numbers (1-indexed) as an integer array answer of size 2, where 1 <= answer[0] < answer[1] <= numbers.length.

The tests are generated such that there is exactly one solution. You may not use the same element twice.

 
Example 1:

Input: numbers = [2,7,11,15], target = 9
Output: [1,2]
Explanation: The sum of 2 and 7 is 9. Therefore index1 = 1, index2 = 2.
Example 2:

Input: numbers = [2,3,4], target = 6
Output: [1,3]
Example 3:

Input: numbers = [-1,0], target = -1
Output: [1,2]
 

Constraints:

2 <= numbers.length <= 3 * 104
-1000 <= numbers[i] <= 1000
numbers is sorted in non-decreasing order.
-1000 <= target <= 1000
The tests are generated such that there is exactly one solution.

*/


Cpp code :

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        
        int n = numbers.size();
        vector<int> v;
        bool flag = 0;
        
        for(int i=0;i<n;i++)
        {
            int rem = target - numbers[i];
            int l=0, r=n-1;
            
            while(l<=r)
            {
                int m = l + (r-l)/2;
                
                if(numbers[m]==rem && m!=i)
                {
                    if(i<m)
                    {
                        v.push_back(i+1);
                        v.push_back(m+1);
                    }
                    else
                    {
                         v.push_back(m+1);
                         v.push_back(i+1);
                    }
                    flag = 1;
                    break;
                }
                else if(numbers[m] > rem)
                {
                    r = m - 1;
                }
                else
                {
                    l = m + 1;
                }
            }
            if(flag == 1)
                break;
            
        }
        
        return v;
    }
};
