// By Chandramani Kumar
// Keep moving and must be simple bro!!!!!
// Espérons le meilleur mais préparez-vous au pire 😎


/* Problem Statement

The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.

Given an integer n, return the number of distinct solutions to the n-queens puzzle.

Example 1:
Input: n = 4
Output: 2
Explanation: There are two distinct solutions to the 4-queens puzzle as shown.

Example 2:
Input: n = 1
Output: 1

Constraints:

1 <= n <= 9

*/


Cpp code :

class Solution {
    unordered_map<int,int> d,rd;
public:
    void solve(vector<vector<int>> &ans,int n,int row,vector<bool> c,vector<int> vec)
  {
      if(row==n)
      {
          ans.push_back(vec);
          return;
      }
      
      for(int i=0;i<n;i++)
      {
          if(c[i]==false&&d[row+i]==0&&rd[row-i+n-1]==0)
          {
              vec.push_back(i+1);
              c[i]=true;
              d[row+i]=1;
              rd[row-i+n-1]=1;
              solve(ans,n,row+1,c,vec);
              vec.pop_back();
              c[i]=false;
              d[row+i]=0;
              rd[row-i+n-1]=0;
          }
      }
  }
    
    int totalNQueens(int n){
        vector<vector<int>> res;
        vector<vector<string>> res1;       
        
        vector<bool> col(n,false);
      
        solve(res,n,0,col,{});
        return res.size();

    }

};
