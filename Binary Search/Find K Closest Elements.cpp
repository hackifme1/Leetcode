// By Chandramani Kumar
// Keep moving and must be simple bro!!!!!
// Espérons le meilleur mais préparez-vous au pire 😎


/* Problem Statement :

Given a sorted integer array arr, two integers k and x, return the k closest integers to x in the array. The result should also be sorted in ascending order.

An integer a is closer to x than an integer b if:

|a - x| < |b - x|, or
|a - x| == |b - x| and a < b
 

Example 1:

Input: arr = [1,2,3,4,5], k = 4, x = 3
Output: [1,2,3,4]

Example 2:

Input: arr = [1,2,3,4,5], k = 4, x = -1
Output: [1,2,3,4]
 

Constraints:

1 <= k <= arr.length
1 <= arr.length <= 104
arr is sorted in ascending order.
-104 <= arr[i], x <= 104

*/


Cpp code :

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int> res;
        int n = arr.size();
        
        int lb = lower_bound(arr.begin(),arr.end(),x) - arr.begin();
        
        if(lb == 0 || k == n){
            for(int i=0;i<k;i++)
            {
                res.push_back(arr[i]);
            }
            
            return res;
        }
        
        int l = lb - 1, r = lb;
        
        while(k--)
        {
            if(l < 0 || (r < n && (abs(arr[l] - x)>abs(arr[r] - x))))
                r++;
            else
                l--;
        }
        
        for(int i = l+1;i<r;i++)
            res.push_back(arr[i]);
        
        return res;
    }
};
