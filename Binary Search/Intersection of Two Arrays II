// By Chandramani Kumar
// Keep moving and must be simple bro!!!!!
// Espérons le meilleur mais préparez-vous au pire 😎


/* Problem Statement 

Given two integer arrays nums1 and nums2, return an array of their intersection. Each element in the result must appear as many times as it shows in both arrays and you may return the result in any order.

Example 1:

Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2,2]
Example 2:

Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
Output: [4,9]
Explanation: [9,4] is also accepted.
 

Constraints:

1 <= nums1.length, nums2.length <= 1000
0 <= nums1[i], nums2[i] <= 1000

*/


Cpp code :

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
       
        vector<int> v;
        int n1 = nums1.size();
        int n2 = nums2.size();
        int f1[1005] = {0};
        int f2[1005] = {0};
        
         for(int i=0;i<n1;i++)
        {
            f1[nums1[i]]++;
        }
        
        for(int i=0;i<n2;i++)
        {
            f2[nums2[i]]++;
        }
        
        if(n1 > n2)
        {
            sort(nums1.begin(),nums1.end());
            
            for(int i=0;i<n2;i++)
            {
                int l = 0, r = n1 - 1;
                
                while(l<=r)
                {
                    int m = l + (r-l)/2;
                    
                    if(nums1[m]==nums2[i] && f1[nums1[m]]>0)
                    {
                        
                            v.push_back(nums2[i]);
                            f1[nums1[m]]--;
                            break;
                        
                    }
                    else if(nums2[i]>nums1[m])
                        l = m +1;
                    else
                        r = m-1;
                }
                
                
            }
            return v;
        }
        else{
            sort(nums2.begin(),nums2.end());
            
            for(int i=0;i<n1;i++)
            {
                int l = 0, r = n2 - 1;
                
                while(l<=r)
                {
                    int m = l + (r-l)/2;
                    
                    if(nums2[m]==nums1[i] && f2[nums2[m]]>0)
                    {
                            v.push_back(nums1[i]);
                            f2[nums2[m]]--;
                            break;
                    }
                    else if(nums1[i]>nums2[m])
                        l = m +1;
                    else
                        r = m-1;
                }
            }
            
            return v;
        }
            

        
    }
};
   
