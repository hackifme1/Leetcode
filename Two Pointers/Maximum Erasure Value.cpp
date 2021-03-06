// By Chandramani Kumar
// Keep moving and must be simple bro!!!!!
// Espérons le meilleur mais préparez-vous au pire 😎


/* Problem Statement

You are given an array of positive integers nums and want to erase a subarray containing unique elements. The score you get by erasing the subarray is equal to the sum of its elements.

Return the maximum score you can get by erasing exactly one subarray.

An array b is called to be a subarray of a if it forms a contiguous subsequence of a, that is, if it is equal to a[l],a[l+1],...,a[r] for some (l,r).


Example 1:

Input: nums = [4,2,4,5,6]
Output: 17
Explanation: The optimal subarray here is [2,4,5,6].
Example 2:

Input: nums = [5,2,1,2,5,2,1,2,5]
Output: 8
Explanation: The optimal subarray here is [5,2,1] or [1,2,5].
 

Constraints:

1 <= nums.length <= 105
1 <= nums[i] <= 104

*/


 Cpp code :

class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        int res = 0;
        map<int,int> mp;
        int temp = 0;
        int i=0,j=0;
        
         while(j<n)
        {
                  while(mp[nums[j]]==1) 
                  {
                         mp[nums[i]]=-1;
                         temp -= nums[i];
                         i++;
                  }
            
                  mp[nums[j]]=1;
                  temp += nums[j];
                  res = max(res, temp);
                  j++;
        }
        
        return res;

        
    }
};
