// By Chandramani Kumar
// Keep moving and must be simple bro!!!!!
// Espérons le meilleur mais préparez-vous au pire 😎


/* Problem Statement :

Given the roots of two binary trees root and subRoot, return true if there is a subtree of root with the same structure and node values of subRoot and false otherwise.

A subtree of a binary tree tree is a tree that consists of a node in tree and all of this node's descendants. The tree tree could also be considered as a subtree of itself.

 
Example 1:

Input: root = [3,4,5,1,2], subRoot = [4,1,2]
Output: true

Example 2:

Input: root = [3,4,5,1,2,null,null,null,null,0], subRoot = [4,1,2]
Output: false
 

Constraints:

The number of nodes in the root tree is in the range [1, 2000].
The number of nodes in the subRoot tree is in the range [1, 1000].
-104 <= root.val <= 104
-104 <= subRoot.val <= 104

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
    vector<TreeNode*> sbroot_address;
    bool check(TreeNode* subRoot,TreeNode* sbroot_address)
    {
        stack<TreeNode*> stckA, stckB;
        
        if(subRoot != NULL)
        stckA.push(subRoot);

        if(sbroot_address != NULL)
        stckB.push(sbroot_address);

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
    
    void find(TreeNode* root, int val)
    {
        if(root == NULL)
            return;
        
        if(root->val == val)
        {
            sbroot_address.push_back(root);
        }
        
        find(root->left, val);
        find(root->right, val);
    }
    
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        sbroot_address.clear();

        find(root,subRoot->val);
        
        if(sbroot_address.size() == 0)
            return false;
        
        for(int i=0;i<sbroot_address.size();i++)
        {
            if(check(subRoot,sbroot_address[i]))
                return true;
        }
        
        return false;
        
    }
};
