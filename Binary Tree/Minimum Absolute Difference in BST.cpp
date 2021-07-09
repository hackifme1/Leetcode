// By Chandramani Kumar
// Keep moving and must be simple bro!!!!!
// Espérons le meilleur mais préparez-vous au pire 😎


/* Problem Statement :

Given the root of a Binary Search Tree (BST), return the minimum absolute difference between the values of any two different nodes in the tree.


Example 1:

Input: root = [4,2,6,1,3]
Output: 1

Example 2:

Input: root = [1,0,48,null,null,12,49]
Output: 1
 

Constraints:

The number of nodes in the tree is in the range [2, 104].
0 <= Node.val <= 105

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
    void getMinimumDifference_help(TreeNode* root, vector<int> &v)
    {
        if(root == NULL)
            return;
        
        getMinimumDifference_help(root->left,v);
        v.push_back(root->val);
        getMinimumDifference_help(root->right,v);
    }
    
    int getMinimumDifference(TreeNode* root) {
         vector<int> v;
         
         getMinimumDifference_help(root,v);
         
         int n = v.size();
        
         int minm = abs(v[1] - v[0]);
        
         for(int i=2;i<n;i++)
         {
             if(abs(v[i]-v[i-1]) < minm)
                 minm = abs(v[i]-v[i-1]);
         }
        
         return minm;
    }
};
