// By Chandramani Kumar
// Keep moving and must be simple bro!!!!!
// Espérons le meilleur mais préparez-vous au pire 😎


/* Problem Statement :

Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.

You must write an algorithm that runs in O(n) time. 

Example 1:

Input: nums = [100,4,200,1,3,2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.

Example 2:

Input: nums = [0,3,7,2,5,8,4,6,0,1]
Output: 9
 

Constraints:

0 <= nums.length <= 105
-109 <= nums[i] <= 109

*/


Cpp code :

// O(n) algo

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> ump;
        set<int> s;
        
        for(int i=0;i<n;i++)
        {
            ump[nums[i]]=1;
            s.insert(nums[i]);
        }
        
        int maxm = 0;
        for(int elem : s)
        {
            if(!ump[elem-1])
            {
                int temp = elem;
                int crnt = 1;
                
                while(ump[temp+1])
                {
                    crnt++;
                    temp++;
                }
               maxm = max(maxm,crnt);
            }
        }
        return maxm;
        
    }
};

// or O(nlogn) algo

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        vector<int> nums1;
        int n = nums.size();
        if(n==0)
            return 0;
        set<int> s;
        for(int i=0;i<n;i++)
        {
            s.insert(nums[i]);
        }
        for(auto it = s.begin();it!=s.end();it++)
            nums1.push_back(*it);
        if(s.size()==1)
            return 1;
        int cnt = 1;
        int maxm = -1;
        
        for(int i=1;i<nums1.size();i++)
        {
            if(nums1[i]==nums1[i-1]+1)
                cnt++;
            else
            {
                maxm =max(maxm,cnt);
                cnt=1;
            }
        }
        maxm = max(maxm,cnt);
        
        return maxm;
    }
};
