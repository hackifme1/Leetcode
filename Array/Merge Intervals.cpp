// By Chandramani Kumar
// Keep moving and must be simple bro!!!!!
// Espérons le meilleur mais préparez-vous au pire 😎


/* Problem Statement

Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.


Example 1:

Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].

Example 2:

Input: intervals = [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considered overlapping.
 

Constraints:

1 <= intervals.length <= 104
intervals[i].length == 2
0 <= starti <= endi <= 104

*/

Cpp code :

bool cmp( const vector<int>& v1, const vector<int>& v2 )
{
    return v1[0] < v2[0];
}

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        
        sort(intervals.begin(),intervals.end(),cmp);
        
        vector<vector<int>> res;
        
        res.push_back({intervals[0][0],intervals[0][1]});
        
        for(int i=1;i<n;i++)
        {
            if(res[res.size()-1][1]>=intervals[i][0])
            { 
                res[res.size()-1][1]=max(res[res.size()-1][1],intervals[i][1]);           
            }
            else
            {
                res.push_back({intervals[i][0],intervals[i][1]});
            }
        }
        
        
        return res;
    }
};

