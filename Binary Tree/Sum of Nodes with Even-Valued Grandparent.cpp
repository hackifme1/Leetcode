// By Chandramani Kumar
// Keep moving and must be simple bro!!!!!
// Espérons le meilleur mais préparez-vous au pire 😎


/* Problem Statement :

Given a binary tree, return the sum of values of nodes with even-valued grandparent.  (A grandparent of a node is the parent of its parent, if it exists.)

If there are no nodes with an even-valued grandparent, return 0. 

Example 1:

Input: root = [6,7,8,2,7,1,3,9,null,1,4,null,null,null,5]
Output: 18

Explanation: The red nodes are the nodes with even-value grandparent while the blue nodes are the even-value grandparents.
 

Constraints:

The number of nodes in the tree is between 1 and 10^4.
The value of nodes is between 1 and 100.

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
    void find_even(TreeNode* root, vector<TreeNode*> &v)
    {
        if(root == NULL)
            return;
        
        if((root->val)%2 == 0)
        v.push_back(root);
        
        find_even(root->left, v);
        find_even(root->right, v);
    }
    
    int sumEvenGrandparent(TreeNode* root) {
        vector<TreeNode*> v;
        int res = 0;
        
        find_even(root,v);
        
        for(int i=0;i<v.size();i++)
        {
            if(v[i]->left != NULL)
            {
                if((v[i]->left)->left != NULL)
                    res+=((v[i]->left)->left->val);
                if((v[i]->left)->right != NULL)
                    res+=((v[i]->left)->right->val);
            }
            
            if(v[i]->right != NULL)
            {
                if((v[i]->right)->right != NULL)
                    res+=((v[i]->right)->right->val);
                if((v[i]->right)->left != NULL)
                    res+=((v[i]->right)->left->val);
            }
        }
        
        return res;
    }
};
