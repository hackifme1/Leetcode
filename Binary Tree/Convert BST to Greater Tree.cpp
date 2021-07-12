// By Chandramani Kumar
// Keep moving and must be simple bro!!!!!
// Espérons le meilleur mais préparez-vous au pire 😎


/* Problem Statement :

Given the root of a Binary Search Tree (BST), convert it to a Greater Tree such that every key of the original BST is changed to the original key plus sum of all keys greater than the original key in BST.

As a reminder, a binary search tree is a tree that satisfies these constraints:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.

Note: This question is the same as 1038: https://leetcode.com/problems/binary-search-tree-to-greater-sum-tree/

 

Example 1:

Input: root = [4,1,6,0,2,5,7,null,null,null,3,null,null,null,8]
Output: [30,36,21,36,35,26,15,null,null,null,33,null,null,null,8]

Example 2:

Input: root = [0,null,1]
Output: [1,null,1]

Example 3:

Input: root = [1,0,2]
Output: [3,3,2]

Example 4:

Input: root = [3,2,4,1]
Output: [7,9,4,10]
 

Constraints:

The number of nodes in the tree is in the range [0, 104].
-104 <= Node.val <= 104
All the values in the tree are unique.
root is guaranteed to be a valid binary search tree.

*/


Cpp code :

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int i;
    
    void inorder(TreeNode* root, vector<int> &v)
    {
        if(root == NULL)
            return;
        
        inorder(root->left, v);
        v.push_back(root->val);
        inorder(root->right, v);
    }
    
    void inorder1(TreeNode* root, vector<int> &v)
    {
        if(root == NULL)
            return;
        
        inorder1(root->left, v);
        root->val = v[i++];
        inorder1(root->right, v);
    }
    
    TreeNode* convertBST(TreeNode* root) {
        vector<int> v;
        
        inorder(root, v);
        
        for(int i=v.size()-2;i>=0;i--)
            v[i] += v[i+1];
        
        for(int i=0;i<v.size();i++)
            cout<<v[i]<<" ";
        
        i = 0;
        inorder1(root,v);
        
        return root;
    }
};
