// By Chandramani Kumar
// Keep moving and must be simple bro!!!!!
// Espérons le meilleur mais préparez-vous au pire 😎


/* Problem Statement :

Given a binary search tree, return a balanced binary search tree with the same node values.

A binary search tree is balanced if and only if the depth of the two subtrees of every node never differ by more than 1.

If there is more than one answer, return any of them.
 

Example 1:

Input: root = [1,null,2,null,3,null,4,null,null]
Output: [2,1,3,null,null,null,4]

Explanation: This is not the only correct answer, [3,1,4,null,2,null,null] is also correct.
 

Constraints:

The number of nodes in the tree is between 1 and 10^4.
The tree nodes will have distinct values between 1 and 10^5.

*/


Cp code :

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
    void inorder(TreeNode* root, vector<int> &v)
    {
        if(root == NULL)
            return;
        
        inorder(root->left, v);
        v.push_back(root->val);
        inorder(root->right, v);
    }
    
    TreeNode* preorder(vector<int> &v, int st, int ed)
    {
        if(st > ed)
            return NULL;
        
        int mid = (st + ed) / 2; 
      
        TreeNode* root = new TreeNode(v[mid]);
        root -> left = preorder(v, st, mid-1); 
        root -> right = preorder(v, mid + 1, ed);
        
        return root;
    }
    
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> v;
        
        inorder(root,v);
        
        int n = v.size();
        
        inorder(root, v);
        
        root = preorder(v, 0, n-1);
        
        return root;        
    }
};
