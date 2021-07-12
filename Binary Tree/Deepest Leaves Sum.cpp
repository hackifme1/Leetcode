// By Chandramani Kumar
// Keep moving and must be simple bro!!!!!
// Espérons le meilleur mais préparez-vous au pire 😎


/* Problem Statement :

Given the root of a binary tree, return the sum of values of its deepest leaves.
 

Example 1:

Input: root = [1,2,3,4,5,null,6,7,null,null,null,null,8]
Output: 15

Example 2:

Input: root = [6,7,8,2,7,1,3,9,null,1,4,null,null,null,5]
Output: 19
 

Constraints:

The number of nodes in the tree is in the range [1, 104].
1 <= Node.val <= 100

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
class Solution {
public:
    void deepestLeavesSum_help(TreeNode* root, int dpth, vector<pair<int,int>> &v)
    {
        if(root == NULL)
            return;
        
        v.push_back(make_pair(root->val, dpth));
        deepestLeavesSum_help(root->left, dpth + 1, v);
        deepestLeavesSum_help(root->right, dpth + 1, v);
    }
    
    int deepestLeavesSum(TreeNode* root) {
        vector<pair<int,int>> v;
        
        deepestLeavesSum_help(root,0,v);
                
        int res = 0, maxm = INT_MIN;
        
        for(int i=0;i<v.size();i++)
        {
            maxm = max(maxm, v[i].second);
        }
        
        for(int i=0;i<v.size();i++)
        {
            if(v[i].second == maxm)
                res+=v[i].first;
        }
        
        return res;
    }
};
