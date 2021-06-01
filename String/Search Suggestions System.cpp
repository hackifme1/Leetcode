// By Chandramani Kumar
// Keep moving and must be simple bro!!!!!
// Espérons le meilleur mais préparez-vous au pire 😎

/* Problem Statement

Given an integer array nums, return the maximum difference between two successive elements in its sorted form. If the array contains less than two elements, return 0.

You must write an algorithm that runs in linear time and uses linear extra space.


Example 1:

Input: nums = [3,6,9,1]
Output: 3
Explanation: The sorted form of the array is [1,3,6,9], either (3,6) or (6,9) has the maximum difference 3.

Example 2:

Input: nums = [10]
Output: 0
Explanation: The array contains less than 2 elements, therefore return 0.
 

Constraints:

1 <= nums.length <= 104
0 <= nums[i] <= 109

*/


Cpp code : O(nlogn) Time Complexity 


class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int n = nums.size();
        if(n<2)
            return 0;
        sort(nums.begin(),nums.end());
        int maxm=-1;
        for(int i=0;i<n-1;i++)
        {
            maxm = max(maxm,abs(nums[i+1]-nums[i]));
        }
        return maxm;
    }
};