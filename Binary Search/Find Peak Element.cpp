// By Chandramani Kumar
// Keep moving and must be simple bro!!!!!
// Espérons le meilleur mais préparez-vous au pire 😎


/* Problem Statement :

A peak element is an element that is strictly greater than its neighbors.

Given an integer array nums, find a peak element, and return its index. If the array contains multiple peaks, return the index to any of the peaks.

You may imagine that nums[-1] = nums[n] = -∞.

You must write an algorithm that runs in O(log n) time.


Example 1:

Input: nums = [1,2,3,1]
Output: 2

Explanation: 3 is a peak element and your function should return the index number 2.

Example 2:

Input: nums = [1,2,1,3,5,6,4]
Output: 5

Explanation: Your function can return either index number 1 where the peak element is 2, or index number 5 where the peak element is 6.
 

Constraints:

1 <= nums.length <= 1000
-231 <= nums[i] <= 231 - 1
nums[i] != nums[i + 1] for all valid i.

*/

Cpp code :

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        
        int l = 0, h = n - 1;
        
        while(l <= h)
        {
            int m = l + (h - l)/2;
            
            if((m == 0 || nums[m] > nums[m-1]) && (m == n-1 || nums[m] > nums[m+1]))
               return m;              
            
            if((m-1) >= 0 && nums[m] <= nums[m-1])
               h = m-1;
            else if((m+1) < n && nums[m] <= nums[m+1])
               l = m+1;             
        }
               
        return l; // 📢 you can return anything here
    }
};
