// By Chandramani Kumar
// Keep moving and must be simple bro!!!!!
// Espérons le meilleur mais préparez-vous au pire 😎


/* Problem Statement :

Given an integer array nums, return the length of the longest strictly increasing subsequence.

A subsequence is a sequence that can be derived from an array by deleting some or no elements without changing the order of the remaining elements. For example, [3,6,2,7] is a subsequence of the array [0,3,1,6,2,2,7].

 

Example 1:

Input: nums = [10,9,2,5,3,7,101,18]
Output: 4

Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.

Example 2:

Input: nums = [0,1,0,3,2,3]
Output: 4

Example 3:

Input: nums = [7,7,7,7,7,7,7]
Output: 1
 

Constraints:

1 <= nums.length <= 2500
-104 <= nums[i] <= 104
 

Follow up: Can you come up with an algorithm that runs in O(n log(n)) time complexity?

*/


Cpp code :

// O(n*n) Time Complexity

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int res[2500] = {0};
        int maxm = INT_MIN;

        for(int i = 0; i < nums.size(); i++)
        {
            int prev_maxm = 0;

            for(int j = 0; j < i; j++)
            {
                if(nums[j] < nums[i])
                {a
                    if(res[j] > prev_maxm)
                    {
                        prev_maxm = res[j];
                    }
                }
            }

            res[i] = prev_maxm + 1;
            maxm = max(maxm,res[i]);
        }
        
        return maxm;
    }
};

// O(n*logn) Time Complexity

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> sqn;
        
        sqn.push_back(nums[0]);
        
        for(int i=1;i<n;i++)
        {
            if(sqn.back() < nums[i])
                sqn.push_back(nums[i]);
            else
            {
                int indx = lower_bound(sqn.begin(),sqn.end(),nums[i]) - sqn.begin();
                sqn[indx] = nums[i];
            }
        }
        
        return sqn.size();
    }
};
