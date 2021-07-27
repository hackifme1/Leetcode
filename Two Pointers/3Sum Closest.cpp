// By Chandramani Kumar
// Keep moving and must be simple bro!!!!!
// Espérons le meilleur mais préparez-vous au pire 😎


/* Problem Statement :

Given an array nums of n integers and an integer target, find three integers in nums such that the sum is closest to target. Return the sum of the three integers. You may assume
that each input would have exactly one solution.


Example 1:

Input: nums = [-1,2,1,-4], target = 1
Output: 2

Explanation: The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
 

Constraints:

3 <= nums.length <= 10^3
-10^3 <= nums[i] <= 10^3
-10^4 <= target <= 10^4

*/


Cpp code :

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        
        sort(nums.begin(), nums.end());
        long long int maxm;
        maxm = INT_MIN;
        
        for(int i=0;i<n-2;i++)
        {
            int k = target - nums[i];
            
            int l = i + 1, r = n - 1;
            
            while(l < r)
            {
                int temp = nums[l] + nums[r];
                int sum = temp + nums[i];
                
                if(abs(target - sum) < abs(target - maxm))
                    maxm = sum;
                
                if(temp < k)
                    l++;
                else
                    r--;
            }
        }
        
        return maxm;
    }
};
