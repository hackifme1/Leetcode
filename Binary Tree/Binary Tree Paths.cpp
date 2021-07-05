// By Chandramani Kumar
// Keep moving and must be simple bro!!!!!
// Espérons le meilleur mais préparez-vous au pire 😎


/* Problem Statement :

Given the root of a binary tree, return all root-to-leaf paths in any order.

A leaf is a node with no children.


Example 1:

Input: root = [1,2,3,null,5]
Output: ["1->2->5","1->3"]

Example 2:

Input: root = [1]
Output: ["1"]
 

Constraints:

The number of nodes in the tree is in the range [1, 100].
-100 <= Node.val <= 100

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
   void binaryTreePaths_help(vector<string>& res, TreeNode* root, string t) {
    
     if(root->left == NULL && root->right == NULL)
    {
        res.push_back(t);
        return;
    }

    if(root->left) 
        binaryTreePaths_help(res, root->left, t + "->" + to_string(root->left->val));
       
    if(root->right) 
        binaryTreePaths_help(res, root->right, t + "->" + to_string(root->right->val));
       
    }

vector<string> binaryTreePaths(TreeNode* root) {
    vector<string> res;
  
    if(root == NULL) 
        return res;
    
    binaryTreePaths_help(res, root, to_string(root->val));
    
    return res;
}
};
