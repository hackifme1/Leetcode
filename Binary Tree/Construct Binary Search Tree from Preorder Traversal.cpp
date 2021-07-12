// By Chandramani Kumar
// Keep moving and must be simple bro!!!!!
// Espérons le meilleur mais préparez-vous au pire 😎


/* Problem Statement :

Given an array of integers preorder, which represents the preorder traversal of a BST (i.e., binary search tree), construct the tree and return its root.

It is guaranteed that there is always possible to find a binary search tree with the given requirements for the given test cases.

A binary search tree is a binary tree where for every node, any descendant of Node.left has a value strictly less than Node.val, and any descendant of Node.right has a value 
strictly greater than Node.val.

A preorder traversal of a binary tree displays the value of the node first, then traverses Node.left, then traverses Node.right.


Example 1:

Input: preorder = [8,5,1,7,10,12]
Output: [8,5,10,1,7,null,12]

Example 2:

Input: preorder = [1,3]
Output: [1,null,3]
 

Constraints:

1 <= preorder.length <= 100
1 <= preorder[i] <= 108
All the values of preorder are unique.

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
    int strt;
    TreeNode* bstFromPreorder_help(vector<int>& pre, vector<int>& in, int st, int ed)
    {
        if(st > ed)
            return NULL;

        TreeNode* root = new TreeNode(pre[strt++]);
        
        if(st == ed)
            return root;

        int indx = ump[root->val];

        root->left = bstFromPreorder_help(pre,in,st,indx-1);
        root->right = bstFromPreorder_help(pre,in,indx+1,ed);

        return root;      
    }
    
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int n = preorder.size();
        strt = 0;
        vector<int> inorder;
        
        inorder = preorder;
        sort(inorder.begin(),inorder.end());
        
        for(int i=0;i<n;i++)
            ump[inorder[i]] = i;
        
        return bstFromPreorder_help(preorder, inorder, 0, n-1);
    }
};
