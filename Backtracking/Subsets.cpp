// By Chandramani Kumar
// Keep moving and must be simple bro!!!!!
// Espérons le meilleur mais préparez-vous au pire 😎


/* Problem Statement :

Given an integer array nums of unique elements, return all possible subsets (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.


Example 1:

Input: nums = [1,2,3]
Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]

Example 2:

Input: nums = [0]
Output: [[],[0]]
 

Constraints:

1 <= nums.length <= 10
-10 <= nums[i] <= 10
All the numbers of nums are unique.

*/


Cpp code :

class Solution {
public:
    vector<vector<int> > subset;

    void subsets_help(vector<int> &v, vector<int> &nums, int indx)
    {
        if(indx < 0)
        {
            if(v.size() > 0)
            subset.push_back(v);
            return;
        }
        
        v.push_back(nums[indx]);
        subsets_help(v,nums,indx-1);
        v.pop_back();
        subsets_help(v,nums,indx-1);
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {    
        subset = {{}};
        vector<int> v;
        int n = nums.size();
        
        subsets_help(v,nums,n-1);
        
        return subset;    
    }
};
