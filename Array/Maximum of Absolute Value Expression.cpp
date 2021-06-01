// By Chandramani Kumar
// Keep moving and must be simple bro!!!!!
// Espérons le meilleur mais préparez-vous au pire 😎


/* Problem Statement

Given two arrays of integers with equal lengths, return the maximum value of:

|arr1[i] - arr1[j]| + |arr2[i] - arr2[j]| + |i - j|

where the maximum is taken over all 0 <= i, j < arr1.length.

 

Example 1:

Input: arr1 = [1,2,3,4], arr2 = [-1,4,5,6]
Output: 13

Example 2:

Input: arr1 = [1,-2,-5,0,10], arr2 = [0,-2,-1,-7,-4]
Output: 20
 

Constraints:

2 <= arr1.length == arr2.length <= 40000
-10^6 <= arr1[i], arr2[i] <= 10^6


*/

Cpp code :


class Solution {
public:
    int maxAbsValExpr(vector<int>& arr1, vector<int>& arr2) {
        int n = arr1.size();
        int min1 = INT_MAX;
        int max1 = INT_MIN;
        int min2 = INT_MAX;
        int max2 = INT_MIN;
        int min3 = INT_MAX;
        int max3 = INT_MIN;
        int min4 = INT_MAX;
        int max4 = INT_MIN;
        
        for(int i=0;i<n;i++)
        {
            if((arr1[i]+arr2[i]+i)<min1)
                min1 = arr1[i]+arr2[i]+i;
            if((arr1[i]+arr2[i]+i)>max1)
                max1 = arr1[i]+arr2[i]+i;
            if((arr1[i]+arr2[i]-i)<min2)
                min2 = arr1[i]+arr2[i]-i;            
            if((arr1[i]+arr2[i]-i)>max2)
                max2 = arr1[i]+arr2[i]-i;
            if((arr1[i]-arr2[i]-i)<min3)
                min3 = arr1[i]-arr2[i]-i;            
            if((arr1[i]-arr2[i]-i)>max3)
                max3 = arr1[i]-arr2[i]-i;
            if((arr1[i]-arr2[i]+i)<min4)
                min4 = arr1[i]-arr2[i]+i;            
            if((arr1[i]-arr2[i]+i)>max4)
                max4 = arr1[i]-arr2[i]+i;
        }
        
        int res = max(max(max1-min1,max2-min2),max(max3-min3,max4-min4));
                
        return res;
    }
};