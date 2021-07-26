// By Chandramani Kumar
// Keep moving and must be simple bro!!!!!
// Espérons le meilleur mais préparez-vous au pire 😎


/* Problem Statement :

Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.
 

Example 1:

Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]

Example 2:

Input: nums = [0,1]
Output: [[0,1],[1,0]]

Example 3:

Input: nums = [1]
Output: [[1]]
 

Constraints:

1 <= nums.length <= 6
-10 <= nums[i] <= 10
All the integers of nums are unique.

*/


Cpp code :

class Solution {
public:
    vector<vector<int>> res;
    
    void permute_help(vector<int> &nums, int indx)
    {
        if(indx >= nums.size())
        {
            res.push_back(nums);
            return;
        }
        
        for(int i=indx;i<nums.size();i++)
        {
            swap(nums[i], nums[indx]);
            permute_help(nums, indx + 1);
            swap(nums[i], nums[indx]);
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        res.clear();
        
        permute_help(nums, 0);
        return res;
    }
};
