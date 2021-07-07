// By Chandramani Kumar
// Keep moving and must be simple bro!!!!!
// Espérons le meilleur mais préparez-vous au pire 😎


/* Problem Statement :

Given the root of a binary search tree, rearrange the tree in in-order so that the leftmost node in the tree is now the root of the tree, and every node has no left child and only one right child.


Example 1:

Input: root = [5,3,6,2,4,null,8,1,null,null,null,7,9]
Output: [1,null,2,null,3,null,4,null,5,null,6,null,7,null,8,null,9]

Example 2:

Input: root = [5,1,7]
Output: [1,null,5,null,7]
 

Constraints:

The number of nodes in the given tree will be in the range [1, 100].
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
class Solution {
public:
    vector<int> v;
    void increasingBST_help(TreeNode* root)
    {
        if(root == NULL)
            return;
        
        increasingBST_help(root->left);
        v.push_back(root->val);
        increasingBST_help(root->right);
    }
    
    TreeNode* increasingBST(TreeNode* root) {
        v.clear();
        
        if(root == NULL)
            return root;
        
        increasingBST_help(root);
        
        TreeNode* res = NULL;
        res = new TreeNode(v[0]);
        
        TreeNode* g = res;
        for(int i=1;i<v.size();i++)
        {
            TreeNode* temp = new TreeNode(v[i]);
            g->right = temp;
            g = temp;
        }
        
        return res;
    }
};
