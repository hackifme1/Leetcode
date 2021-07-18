// By Chandramani Kumar
// Keep moving and must be simple bro!!!!!
// Espérons le meilleur mais préparez-vous au pire 😎


/* Problem Statement :

Given the root of a binary tree, calculate the vertical order traversal of the binary tree.

For each node at position (row, col), its left and right children will be at positions (row + 1, col - 1) and (row + 1, col + 1) respectively. The root of the tree is at (0, 0).

The vertical order traversal of a binary tree is a list of top-to-bottom orderings for each column index starting from the leftmost column and ending on the rightmost column. 
There may be multiple nodes in the same row and same column. In such a case, sort these nodes by their values.

Return the vertical order traversal of the binary tree.

 
Example 1:

Input: root = [3,9,20,null,null,15,7]
Output: [[9],[3,15],[20],[7]]

Explanation:
Column -1: Only node 9 is in this column.
Column 0: Nodes 3 and 15 are in this column in that order from top to bottom.
Column 1: Only node 20 is in this column.
Column 2: Only node 7 is in this column.


Example 2:

Input: root = [1,2,3,4,5,6,7]
Output: [[4],[2],[1,5,6],[3],[7]]

Explanation:
Column -2: Only node 4 is in this column.
Column -1: Only node 2 is in this column.
Column 0: Nodes 1, 5, and 6 are in this column.
          1 is at the top, so it comes first.
          5 and 6 are at the same position (2, 0), so we order them by their value, 5 before 6.
Column 1: Only node 3 is in this column.
Column 2: Only node 7 is in this column.


Example 3:


Input: root = [1,2,3,4,6,5,7]
Output: [[4],[2],[1,5,6],[3],[7]]

Explanation:
This case is the exact same as example 2, but with nodes 5 and 6 swapped.
Note that the solution remains the same since 5 and 6 are in the same location and should be ordered by their values.
 

Constraints:

The number of nodes in the tree is in the range [1, 1000].
0 <= Node.val <= 1000

*/


Cpp code :

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
// bool comp(pair<int,pair<int,int>> &p1, pair<int,pair<int,int>> &p2)
// {
//     return p1    
// }

class Solution {
public:
    
    void verticalTraversal_help(TreeNode* root, int lvl, int col, vector<pair<int,pair<int,int>>> &v)
    {
        if(root == NULL)
            return;
        
        v.push_back(make_pair(col, make_pair(lvl, root->val)));
        verticalTraversal_help(root->left, lvl + 1, col - 1, v);
        verticalTraversal_help(root->right, lvl + 1, col + 1, v);
    }
    
    vector<vector<int>> verticalTraversal(TreeNode* root) {       
        if(root == NULL)
            return {{}};
        
        vector<pair<int,pair<int,int>>> v;
        
        verticalTraversal_help(root, 0, 0, v);        
        
        sort(v.begin(), v.end());
        
        int minm = INT_MAX, maxm = INT_MIN;
        
        for(int i=0;i<v.size();i++)
        {
            minm = min(minm, v[i].first);
            maxm = max(maxm, v[i].first);
        }
        
        vector<vector<int>> res(maxm-minm+1);

        for(int i=0;i<v.size();i++)
        {
            res[v[i].first + abs(minm)].push_back(v[i].second.second);
        }
        
        return res;
    }
};
