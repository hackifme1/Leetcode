// By Chandramani Kumar
// Keep moving and must be simple bro!!!!!
// Espérons le meilleur mais préparez-vous au pire 😎


/* Problem Statement :

Given the root of a binary search tree (BST) with duplicates, return all the mode(s) (i.e., the most frequently occurred element) in it.

If the tree has more than one mode, return them in any order.

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than or equal to the node's key.
The right subtree of a node contains only nodes with keys greater than or equal to the node's key.
Both the left and right subtrees must also be binary search trees.
 

Example 1:

Input: root = [1,null,2,2]
Output: [2]

Example 2:

Input: root = [0]
Output: [0]
 

Constraints:

The number of nodes in the tree is in the range [1, 104].
-10^5 <= Node.val <= 10^5
 

Follow up: Could you do that without using any extra space? (Assume that the implicit stack space incurred due to recursion does not count).

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
    void preorder(TreeNode* root, vector<int> &v)
    {
        if(root == NULL)
            return;
       
        preorder(root->left,v); 
        v.push_back(root->val);
        preorder(root->right,v);
    }
    
    vector<int> findMode(TreeNode* root) {
        vector<int> v;
        map<int,int> mp;
        vector<int> res;
        
        preorder(root,v);
        
        for(int i=0;i<v.size();i++)
            mp[v[i]]++;
        
        int maxm = INT_MIN;
        
        for(auto elem : mp)
        {
            if(elem.second > maxm)
            {
                maxm = elem.second;
            }
        }
        
        for(auto elem : mp)
        {
            if(elem.second == maxm)
            {
                res.push_back(elem.first);
            }
        }
        
        return res;
    }
};
