// By Chandramani Kumar
// Keep moving and must be simple bro!!!!!
// Espérons le meilleur mais préparez-vous au pire 😎


/* Problem Statement :

Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:

0 <= a, b, c, d < n
a, b, c, and d are distinct.
nums[a] + nums[b] + nums[c] + nums[d] == target
You may return the answer in any order.


Example 1:

Input: nums = [1,0,-1,0,-2,2], target = 0
Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]

Example 2:

Input: nums = [2,2,2,2,2], target = 8
Output: [[2,2,2,2]]
 

Constraints:

1 <= nums.length <= 200
-109 <= nums[i] <= 109
-109 <= target <= 109

*/


Cpp code :

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        
        vector<vector<int>> res;   
        map<int,vector<pair<int,int>>> mp;
        set<vector<int>> st;
        
        for(int i=0;i<n-1;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                mp[nums[i] + nums[j]].push_back(make_pair(i,j));
            }
        }
        
         for(int i=0;i<n-1;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                int s = nums[i] + nums[j];
                int srch = target - s;
                
                if(mp.find(srch) != mp.end())
                {
                    for(int k=0;k<mp[srch].size();k++)
                    {
                        if((mp[srch][k].first != i && mp[srch][k].second != j) && (mp[srch][k].first != j && mp[srch][k].second != i))
                        {
                            vector<int> t = {nums[i],nums[j],nums[mp[srch][k].first],nums[mp[srch][k].second]};
                            sort(t.begin(),t.end());
                            if(st.find(t) == st.end())
                            {
                                st.insert(t);
                                res.push_back(t);     
                            }                   
                        } 
                    }
                }
            }
        }
        
        sort(res.begin(),res.end());
        return res;
    }
};
