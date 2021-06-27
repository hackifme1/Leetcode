// By Chandramani Kumar
// Keep moving and must be simple bro!!!!!
// Espérons le meilleur mais préparez-vous au pire 😎


/* Problem Statement :

You are given an m x n integer matrix grid, where m and n are both even integers, and an integer k.

The matrix is composed of several layers, which is shown in the below image, where each color is its own layer:

A cyclic rotation of the matrix is done by cyclically rotating each layer in the matrix. To cyclically rotate a layer once, each element in the layer will take the place of the 
adjacent element in the counter-clockwise direction. An example rotation is shown below:
Return the matrix after applying k cyclic rotations to it.


Example 1:

Input: grid = [[40,10],[30,20]], k = 1
Output: [[10,20],[40,30]]

Explanation: The figures above represent the grid at every state.

Example 2.
  
Input: grid = [[1,2,3,4],[5,6,7,8],[9,10,11,12],[13,14,15,16]], k = 2
Output: [[3,4,8,12],[2,11,10,16],[1,7,6,15],[5,9,13,14]]

Explanation: The figures above represent the grid at every state.
 

Constraints:

m == grid.length
n == grid[i].length
2 <= m, n <= 50
Both m and n are even integers.
1 <= grid[i][j] <= 5000
1 <= k <= 109


*/


Cpp code :

class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int R = k;
        int idx_i = 0, idx_j = 0;
        int M = grid.size();
        int N = grid[0].size();

	    vector<int> temp;
        
        for(int x=M-1, y=N-1; x>0 && y>0; x-=2, y-=2,idx_i++,idx_j++)
        {	
            int rtte = R%(2*(x+y));
            int sz = 2*(x+y);
            int i=idx_i, j=idx_j;

            for(int cnt=0; cnt<sz; cnt++)
            {	
                temp.push_back(grid[i][j]);

                if(j==idx_i && i<idx_i+x)
                {
                    	i++;	
                }
                else if(i==idx_i+x && j<idx_j+y)
                {	
                    j++;
            	}
                else if(j==idx_j+y && i>idx_i)
                {	
                    i--;
            	}
                else if(i==idx_i && j>idx_j)
                {
                    	j--;
            	}
            }

            i = idx_i, j = idx_j;

            int posn;

            for(int cnt=0; cnt<sz; cnt++)
            {	
                posn = (cnt-rtte)%sz;
                posn = (posn<0)? posn+sz : posn;
                grid[i][j] = temp[posn];

                if(j==idx_i && i<idx_i+x)
                {	
                    i++;	
                }
                else if(i==idx_i+x && j<idx_j+y)
                {	
                    j++;
                }
                else if(j==idx_j+y && i>idx_i)
                {	
                    i--;	
                }
                else if(i==idx_i && j>idx_j)
                {	
                    j--;	
                }
            }

            temp.clear();
        }
        
        return grid;
    }
};
