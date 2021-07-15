// By Chandramani Kumar
// Keep moving and must be simple bro!!!!!
// Espérons le meilleur mais préparez-vous au pire 😎


/* Problem Statement :

Given an integer array nums, return the number of triplets chosen from the array that can make triangles if we take them as side lengths of a triangle.


Example 1:

Input: nums = [2,2,3,4]
Output: 3

Explanation: Valid combinations are: 
2,3,4 (using the first 2)
2,3,4 (using the second 2)
2,2,3


Example 2:

Input: nums = [4,2,3,4]
Output: 4
 

Constraints:

1 <= nums.length <= 1000
0 <= nums[i] <= 1000

*/


Cpp code :

class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        
        int res = 0;
        
        for(int i=0;i<n-2;i++)
        {
            int k = i + 2;
            for(int j=i+1; j < (n-1) && nums[i] != 0; j++)
            {
                k = lower_bound(nums.begin(), nums.end(), nums[i] + nums[j]) - nums.begin();
                res += (k - j - 1);
            }
        }
        
        return res;
    }
};
