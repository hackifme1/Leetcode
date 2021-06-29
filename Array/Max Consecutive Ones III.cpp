// By Chandramani Kumar
// Keep moving and must be simple bro!!!!!
// Espérons le meilleur mais préparez-vous au pire 😎


/* Problem Statement :

Given a binary array nums and an integer k, return the maximum number of consecutive 1's in the array if you can flip at most k 0's.

 

Example 1:

Input: nums = [1,1,1,0,0,0,1,1,1,1,0], k = 2
Output: 6
Explanation: [1,1,1,0,0,1,1,1,1,1,1]

Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.

Example 2:

Input: nums = [0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1], k = 3
Output: 10
Explanation: [0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1]

Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.
 

Constraints:

1 <= nums.length <= 105
nums[i] is either 0 or 1.
0 <= k <= nums.length

*/


Cpp code :

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int l = 0, cnt =0;
        int maxm = INT_MIN;
        
        for(int i=0;i<n;i++)
        {
            if(nums[i] == 0)
                cnt++;
            
            while(cnt>k)
            {
                if(nums[l] == 0)
                    cnt--;
                
                l++;
            }
            
            maxm = max(maxm,i-l+1);
        }
        
        return maxm;
    }
};
