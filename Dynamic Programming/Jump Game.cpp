// By Chandramani Kumar
// Keep moving and must be simple bro!!!!!
// Espérons le meilleur mais préparez-vous au pire 😎


/* Problem Statement :

Given an array of non-negative integers nums, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Determine if you are able to reach the last index.

 
Example 1:

Input: nums = [2,3,1,1,4]
Output: true

Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.

Example 2:

Input: nums = [3,2,1,0,4]
Output: false

Explanation: You will always arrive at index 3 no matter what. Its maximum jump length is 0, which makes it impossible to reach the last index.
 

Constraints:

1 <= nums.length <= 104
0 <= nums[i] <= 105

*/


Cpp code :
// Dynamic Programming Approach

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<bool> dp(n);
        dp[n-1] = true;
        
        for(int i=n-2;i>=0;i--)
        {
            for(int j=0;j<=nums[i] && (i+j)<n;j++)
            {
                if(dp[i+j] == true)
                {
                    dp[i] = true;
                    break;
                }
            }
        }
        
        return dp[0];
    }
};


// Greedy Approach
class Solution {
public:
    bool canJump(vector<int>& nums) {
    int n = nums.size();
      
    if(n == 0 || n == 1)
    return true;
        
    int maxidx = nums[0];
    int crrmaxidx = nums[0];
        
    for(int i = 1; i <= min(n, maxidx); i++)
    {
        crrmaxidx = max(crrmaxidx, i + nums[i]);

        if(i == (n - 1))
            return true;
        
        if(i == maxidx)
        {
            maxidx = crrmaxidx;
        }
    }
        
    return false;
    
    }
};
