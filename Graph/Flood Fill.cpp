// By Chandramani Kumar
// Keep moving and must be simple bro!!!!!
// Espérons le meilleur mais préparez-vous au pire 😎


/* Problem Statement :

An image is represented by an m x n integer grid image where image[i][j] represents the pixel value of the image.

You are also given three integers sr, sc, and newColor. You should perform a flood fill on the image starting from the pixel image[sr][sc].

To perform a flood fill, consider the starting pixel, plus any pixels connected 4-directionally to the starting pixel of the same color as the starting pixel, plus any pixels 
connected 4-directionally to those pixels (also with the same color), and so on. Replace the color of all of the aforementioned pixels with newColor.

Return the modified image after performing the flood fill.

 
Example 1:

Input: image = [[1,1,1],[1,1,0],[1,0,1]], sr = 1, sc = 1, newColor = 2
Output: [[2,2,2],[2,2,0],[2,0,1]]

Explanation: From the center of the image with position (sr, sc) = (1, 1) (i.e., the red pixel), all pixels connected by a path of the same color as the starting pixel (i.e., 
the blue pixels) are colored with the new color.
Note the bottom corner is not colored 2, because it is not 4-directionally connected to the starting pixel.


Example 2:

Input: image = [[0,0,0],[0,0,0]], sr = 0, sc = 0, newColor = 2
Output: [[2,2,2],[2,2,2]]
 

Constraints:

m == image.length
n == image[i].length
1 <= m, n <= 50
0 <= image[i][j], newColor < 216
0 <= sr < m
0 <= sc < n

*/


Cpp code :

class Solution {
public:
    int n, m, chk_color, newColor1;
    
    void dfs(vector<vector<int>>& image, int sr, int sc, vector<vector<bool>> &vis)
    {
        if(sr < 0 || sc > m-1 || sr > n-1 || sc < 0 || image[sr][sc] != chk_color || vis[sr][sc] == true )
            return;
        
        vis[sr][sc] = true;
        
        image[sr][sc] = newColor1;
        
        dfs(image, sr-1, sc, vis);
        dfs(image, sr, sc-1, vis);
        dfs(image, sr, sc+1, vis);
        dfs(image, sr+1, sc, vis);
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        n = image.size();
        m = image[0].size();
        newColor1 = newColor;
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        chk_color = image[sr][sc];
        
        dfs(image, sr, sc, vis);
        
        return image;
    }
};
