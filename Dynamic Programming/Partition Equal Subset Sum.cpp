// By Chandramani Kumar
// Keep moving and must be simple bro!!!!!
// Espérons le meilleur mais préparez-vous au pire 😎


/* Problem Statement :

Given a non-empty array nums containing only positive integers, find if the array can be partitioned into two subsets such that the sum of elements in both subsets is equal.

 

Example 1:

Input: nums = [1,5,11,5]
Output: true
Explanation: The array can be partitioned as [1, 5, 5] and [11].

Example 2:

Input: nums = [1,2,3,5]
Output: false
Explanation: The array cannot be partitioned into equal sum subsets.
 

Constraints:

1 <= nums.length <= 200
1 <= nums[i] <= 100

*/


Cpp code :

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int s=0;
        
        int N=nums.size();
        int arr[N];
        for(int i=0;i<N;i++)
            arr[i]=nums[i];
        
     for(int i=0;i<N;i++)
        s=s+arr[i];
        
        if(s%2!=0)
        return false;
    
        s=s/2;
        int dp[N+1][s+1];
        
        for(int i=0;i<=N;i++)
        dp[i][0]=1;
        
        for(int i=1;i<=s;i++)
        dp[0][i]=0;
        
        for(int i=1;i<=N;i++)
        {
            for(int j=1;j<=s;j++)
            {
                if(arr[i-1]>j)
                dp[i][j]=dp[i-1][j];
                if(arr[i-1]<=j)
                dp[i][j]=dp[i-1][j-arr[i-1]]|dp[i-1][j];
            }
        }
        if(dp[N][s]==1)
        return true;
        else
        return false;
    }
};
