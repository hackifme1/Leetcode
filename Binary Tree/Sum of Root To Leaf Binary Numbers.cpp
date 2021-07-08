// By Chandramani Kumar
// Keep moving and must be simple bro!!!!!
// Espérons le meilleur mais préparez-vous au pire 😎


/* Problem Statement :

You are given the root of a binary tree where each node has a value 0 or 1.  Each root-to-leaf path represents a binary number starting with the most significant bit.  For example, if the path is 0 -> 1 -> 1 -> 0 -> 1, then this could represent 01101 in binary, which is 13.

For all leaves in the tree, consider the numbers represented by the path from the root to that leaf.

Return the sum of these numbers. The answer is guaranteed to fit in a 32-bits integer.

 

Example 1:

Input: root = [1,0,1,0,1,0,1]
Output: 22

Explanation: (100) + (101) + (110) + (111) = 4 + 5 + 6 + 7 = 22

Example 2:

Input: root = [0]
Output: 0

Example 3:

Input: root = [1]
Output: 1

Example 4:

Input: root = [1,1]
Output: 3
 

Constraints:

The number of nodes in the tree is in the range [1, 1000].
Node.val is 0 or 1.

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
    string str = "";
  
    int bin_dec(string s)
    {
        int dec_value = 0;

        int base = 1;

        int len = s.size();
        
        for (int i = len - 1; i >= 0; i--) 
        {
            if (s[i] == '1')
                dec_value += base;
            base = base * 2;
        }

        return dec_value;
    }
    
    void sumRootToLeaf_help(TreeNode* root,vector<string> &v)
    {
        if(root == NULL)
            return;
        if(root->left == NULL && root->right == NULL)
        {
            char ch = (root->val + '0');
            v.push_back(str + ch);
            return;
        }
        char ch = (root->val + '0');
        str = str + (ch);
        sumRootToLeaf_help(root->left, v);
        sumRootToLeaf_help(root->right, v);
        str.pop_back();
    }
    
    int sumRootToLeaf(TreeNode* root) {
        str = "";
        if(root == NULL)
            return NULL;
        
        int res = 0;
        
        vector<string> v;
        sumRootToLeaf_help(root,v);
        
         for(int i=0;i<v.size();i++)
         {
             cout<<v[i]<<" ";
         }
        for(int i=0;i<v.size();i++)
        {
            res += bin_dec(v[i]);
        }
        
        return res;
    }
};
