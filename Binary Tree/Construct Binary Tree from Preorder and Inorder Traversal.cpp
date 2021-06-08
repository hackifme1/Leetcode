// By Chandramani Kumar
// Keep moving and must be simple bro!!!!!
// Espérons le meilleur mais préparez-vous au pire 😎


/* Problem Statement :

Given two integer arrays preorder and inorder where preorder is the preorder traversal of a binary tree and inorder is the inorder traversal of the same tree, construct and return the binary tree.
 

Example 1:

Input: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
Output: [3,9,20,null,null,15,7]

Example 2:

Input: preorder = [-1], inorder = [-1]
Output: [-1]
 

Constraints:

1 <= preorder.length <= 3000
inorder.length == preorder.length
-3000 <= preorder[i], inorder[i] <= 3000
preorder and inorder consist of unique values.
Each value of inorder also appears in preorder.
preorder is guaranteed to be the preorder traversal of the tree.
inorder is guaranteed to be the inorder traversal of the tree.

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
    unordered_map<int,int> ump;
public:
    TreeNode* newNode(int x)
    {
        TreeNode* nw = new TreeNode();
        nw -> val = x;
        nw -> left = NULL;
        nw -> right = NULL;

        return nw;
    }
    
    int strt = 0;

    TreeNode* buildTree_help(vector<int>& pre, vector<int>& in, int st, int ed)
    {
        if(st>ed)
            return NULL;

        TreeNode* node = newNode(pre[strt]);
        strt++;


        if(st == ed)
            return node;

        int indx = ump[node->val];

        node->left = buildTree_help(pre,in,st,indx-1);
        node->right = buildTree_help(pre,in,indx+1,ed);

        return node;      

    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = inorder.size();
        for(int i=0;i<n;i++)
            ump[inorder[i]] = i;
        
      TreeNode* root = buildTree_help(preorder,inorder,0,n-1);      
        
        return root;
    }
};
