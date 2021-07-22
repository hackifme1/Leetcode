// By Chandramani Kumar
// Keep moving and must be simple bro!!!!!
// Espérons le meilleur mais préparez-vous au pire 😎


/* Problem Statement :

Given an array nums, partition it into two (contiguous) subarrays left and right so that:

Every element in left is less than or equal to every element in right.
left and right are non-empty.
left has the smallest possible size.

Return the length of left after such a partitioning.  It is guaranteed that such a partitioning exists.
 

Example 1:

Input: nums = [5,0,3,8,6]
Output: 3

Explanation: left = [5,0,3], right = [8,6]

Example 2:

Input: nums = [1,1,1,0,6,12]
Output: 4

Explanation: left = [1,1,1,0], right = [6,12]
 

Note:

2 <= nums.length <= 30000
0 <= nums[i] <= 106
It is guaranteed there is at least one way to partition nums as described.

*/


Cpp code :

class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        pair<int,int> minm = {INT_MAX,-1};
        
        int n = nums.size();
        
        int l = 0, r = 0;
        
        int maxm = nums[0], temp = nums[0];
        
        while(l <= r && r < n)
        {
            temp = max(temp, nums[r]);
            
            if(nums[r] < maxm)
            {
                maxm = temp;
                l = r;                
            }
            r++;
        }
        
        return l + 1;
    }
};
