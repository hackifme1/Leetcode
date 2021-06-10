// By Chandramani Kumar
// Keep moving and must be simple bro!!!!!
// Espérons le meilleur mais préparez-vous au pire 😎


/*Problem Statement 

Given two integer arrays nums1 and nums2, return an array of their intersection. Each element in the result must be unique and you may return the result in any order.

Example 1:

Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2]
Example 2:

Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
Output: [9,4]
Explanation: [4,9] is also accepted.
 

Constraints:

1 <= nums1.length, nums2.length <= 1000
0 <= nums1[i], nums2[i] <= 1000
*/


Cpp code :

// Two pointer Approach along with hashmap concept

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    vector<int> res;
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        
    int flag[1001] = {0};
    int m = nums1.size();
    int n = nums2.size();
    int l = 0, r = 0;
    
    while(l<m && r<n)
    {
        if(nums1[l]<nums2[r])
        l++;
        else if(nums1[l]>nums2[r])
        r++;
        else
        {
            if(flag[nums1[l]]==0)
            res.push_back(nums1[l]);
            flag[nums1[l]] = 1;
            l++;
            r++;
        }
    }
    
    return res;                   
    }
};


// Binary Search

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> v;
        map<int,int> mp;
        int n1 = nums1.size();
        int n2 = nums2.size();
        
        if(n1 > n2)
        {
            sort(nums1.begin(),nums1.end());
            
            for(int i=0;i<n2;i++)
            {
                if(mp[nums2[i]]==1)
                    continue;
                int l = 0, r = n1 - 1;
                
                while(l<=r)
                {
                    int m = l + (r-l)/2;
                    
                    if(nums1[m]==nums2[i])
                    {
                        
                            v.push_back(nums2[i]);
                            break;
                        
                    }
                    else if(nums2[i]>nums1[m])
                        l = m +1;
                    else
                        r = m-1;
                }
                
                mp[nums2[i]] = 1;
            }
            return v;
        }
        else{
            sort(nums2.begin(),nums2.end());
            
            for(int i=0;i<n1;i++)
            {
                if(mp[nums1[i]]==1)
                    continue;
                int l = 0, r = n2 - 1;
                
                while(l<=r)
                {
                    int m = l + (r-l)/2;
                    
                    if(nums2[m]==nums1[i])
                    {
                            v.push_back(nums1[i]);
                            break;
                    }
                    else if(nums1[i]>nums2[m])
                        l = m +1;
                    else
                        r = m-1;
                }
                mp[nums1[i]] = 1;
            }
            
            return v;
        }
            

        
    }
};
