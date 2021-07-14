// By Chandramani Kumar
// Keep moving and must be simple bro!!!!!
// Espérons le meilleur mais préparez-vous au pire 😎


/* Problem Statement :

Given the root of a binary tree, return the bottom-up level order traversal of its nodes' values. (i.e., from left to right, level by level from leaf to root).


Example 1:

Input: root = [3,9,20,null,null,15,7]
Output: [[15,7],[9,20],[3]]

Example 2:

Input: root = [1]
Output: [[1]]

Example 3:

Input: root = []
Output: []
 

Constraints:

The number of nodes in the tree is in the range [0, 2000].
-1000 <= Node.val <= 1000

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
 bool comp(pair<int,int> &p1, pair<int,int> &p2)
 {
    return p1.second > p2.second;
 }
    
class Solution {
public:

    void levelOrderBottom_help(TreeNode* root, int lvl, vector<pair<int,int>> &v)
    {
        if(root == NULL)
            return;
        
        v.push_back(make_pair(root->val,lvl));
        levelOrderBottom_help(root->left, lvl + 1, v);
        levelOrderBottom_help(root->right, lvl + 1, v);
    }
    
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res1;
        
        if(root == NULL)
            return res1;
        
        vector<pair<int,int>> v;
        
        levelOrderBottom_help(root,0,v);
        
        int maxm = INT_MIN;
           
        for(int i=0;i<v.size();i++)
            maxm = max(maxm,v[i].second);

        vector<vector<int>> res(maxm+1);

        for(int i=0;i<v.size();i++)
        {
           res[v[i].second].push_back(v[i].first);
        }
        
        reverse(res.begin(),res.end());
        
        return res;
    }
};
