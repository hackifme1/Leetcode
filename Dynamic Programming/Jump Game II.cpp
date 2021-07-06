// By Chandramani Kumar
// Keep moving and must be simple bro!!!!!
// Espérons le meilleur mais préparez-vous au pire 😎


/* Problem Statement :

Given an array of non-negative integers nums, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Your goal is to reach the last index in the minimum number of jumps.

You can assume that you can always reach the last index.

 

Example 1:

Input: nums = [2,3,1,1,4]
Output: 2

Explanation: The minimum number of jumps to reach the last index is 2. Jump 1 step from index 0 to 1, then 3 steps to the last index.

Example 2:

Input: nums = [2,3,0,1,4]
Output: 2
 

Constraints:

1 <= nums.length <= 104
0 <= nums[i] <= 1000

*/


Cpp code :

// Dynamic Programming Approach

class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> dp(n,INT_MAX);
        
        dp[n-1] = 0;
        
        for(int i=n-2;i>=0;i--)
        {
            int tk;
            if((nums[i] + i) >= (n-1))
                tk = 1;
            else
                tk = INT_MAX;
            
            for(int j=1;j<=nums[i] && (i+j)<n;j++)
            {
                if(tk>dp[i+j])
                {
                    dp[i] = min(tk,dp[i+j] + 1);
                    tk = dp[i+j];
                }
            }
        }
        
        return dp[0];
    }
};


// Greedy Approach

class Solution {
public:
    int jump(vector<int>& nums) {
    int n = nums.size();

    if(n == 0 || n == 1)
    return 0;
        
    int maxidx = nums[0];
    int crrmaxidx = nums[0];
    int res = 1;

    for(int i = 1; i <= min(n, maxidx); i++)
    {
        crrmaxidx = max(crrmaxidx, i + nums[i]);
        
        if(i == n - 1)
        return res;
        
        if(i == maxidx)
        {
            maxidx = crrmaxidx;
            res++;
        }
    }

    return -1;
    }
};
