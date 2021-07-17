// By Chandramani Kumar
// Keep moving and must be simple bro!!!!!
// Espérons le meilleur mais préparez-vous au pire 😎


/* Problem Statement :

You are given an array arr which consists of only zeros and ones, divide the array into three non-empty parts such that all of these parts represent the same binary value.

If it is possible, return any [i, j] with i + 1 < j, such that:

arr[0], arr[1], ..., arr[i] is the first part,
arr[i + 1], arr[i + 2], ..., arr[j - 1] is the second part, and
arr[j], arr[j + 1], ..., arr[arr.length - 1] is the third part.
All three parts have equal binary values.
If it is not possible, return [-1, -1].

Note that the entire part is used when considering what binary value it represents. For example, [1,1,0] represents 6 in decimal, not 3. Also, leading zeros are allowed, so
[0,1,1] and [1,1] represent the same value.


Example 1:

Input: arr = [1,0,1,0,1]
Output: [0,3]

Example 2:

Input: arr = [1,1,0,1,1]
Output: [-1,-1]

Example 3:

Input: arr = [1,1,0,0,1]
Output: [0,2]
 

Constraints:

3 <= arr.length <= 3 * 104
arr[i] is 0 or 1

*/


Cpp code :

class Solution {
public:
    vector<int> threeEqualParts(vector<int>& arr) {
        int n = arr.size();
        
        int cnt = 0;
        
        for(int i=0;i<n;i++)
        {
            if(arr[i] == 1)
                cnt++;
        }
        
        if(cnt == 0)
            return {0, 2};
        
        if(cnt % 3 != 0)
            return {-1, -1};
        
        int k = cnt/3, l = -1, r = -1, m = -1;
        
        int indx1;
        
        for(int i=0;i<n;i++)
        {
            if(arr[i] == 1)
            {
                indx1 = i;
                break;
            }
        }
        
        l = indx1;
        
        cnt = 0;
        
         for(int i=0;i<n;i++)
        {
            if(arr[i] == 1)
                cnt++;
             
             if(cnt == k+1)
             {
                 indx1 = i;
                 break;
             }
        }
        
        m = indx1;
        
        cnt = 0;
        
         for(int i=0;i<n;i++)
        {
            if(arr[i] == 1)
                cnt++;
             
             if(cnt == 2*k+1)
             {
                 indx1 = i;
                 break;
             }
        }
        
        r = indx1;
                
        for(;r<n;)
        {
            if(arr[l] == arr[m] && arr[m] == arr[r])
                l++,m++,r++;
            else
            {
                break;
            }
        }
        
        if(r == n)
            return {l-1, m};
        
        return {-1, -1};
            
    }
};
