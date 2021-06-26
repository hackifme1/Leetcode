// By Chandramani Kumar
// Keep moving and must be simple bro!!!!!
// Espérons le meilleur mais préparez-vous au pire 😎


/* Problem Statement :

Given the roots of two binary trees p and q, write a function to check if they are the same or not.

Two binary trees are considered the same if they are structurally identical, and the nodes have the same value.
 

Example 1:
Input: p = [1,2,3], q = [1,2,3]
Output: true

Example 2:
Input: p = [1,2], q = [1,null,2]
Output: false

Example 3:
Input: p = [1,2,1], q = [1,1,2]
Output: false
 

Constraints:

The number of nodes in both trees is in the range [0, 100].
-104 <= Node.val <= 104


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
    bool isSameTree(TreeNode* p, TreeNode* q) {
         stack<TreeNode*> stckA, stckB;
        
    if(p!=NULL)
    stckA.push(p);

    if(q!=NULL)
    stckB.push(q);

    while(!stckA.empty() && !stckB.empty())
    {
        TreeNode* topA = stckA.top();
        TreeNode* topB = stckB.top();
        stckA.pop();
        stckB.pop();
         
        if(topA->val != topB->val)
        return false;

        if(topA->right!=NULL)
        stckA.push(topA->right);

        if(topB->right!=NULL)
        stckB.push(topB->right);

        if(stckA.size()!=stckB.size())
        return false;

        if(topA->left!=NULL)
        stckA.push(topA->left);

        if(topB->left!=NULL)
        stckB.push(topB->left);

        if(stckA.size()!=stckB.size())
        return false;
    }

    return stckA.size()==stckB.size();
    }
};
