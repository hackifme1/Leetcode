// By Chandramani Kumar
// Keep moving and must be simple bro!!!!!
// Espérons le meilleur mais préparez-vous au pire 😎


/* Problem Statement :

Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).

 

Example 1:


Input: root = [1,2,2,3,4,4,3]
Output: true
Example 2:


Input: root = [1,2,2,null,3,null,3]
Output: false
 

Constraints:

The number of nodes in the tree is in the range [1, 1000].
-100 <= Node.val <= 100
 

Follow up: Could you solve it both recursively and iteratively?


*/

// iterative version

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
    bool isSymmetric(TreeNode* root) {
        TreeNode *lft, *rit;
        
        if (!root)
            return true;
        
        stack<TreeNode*> stck1, stck2;
        
        stck1.push(root->left);
        stck2.push(root->right);

        while (!stck1.empty() && !stck2.empty())
        {
            lft = stck1.top();
            stck1.pop();
            
            rit = stck2.top();
            stck2.pop();
            
            if ( lft == NULL && rit == NULL)
                continue;
            
            if (lft == NULL || rit == NULL)
                return false;
            
            if (lft->val != rit->val)
                return false;
            
            stck1.push(lft->right);
            stck1.push(lft->left);
            stck2.push(rit->left);
            stck2.push(rit->right);           
        }
        
        return true;
    }
};


// recursive version

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
    bool tru(TreeNode* root1,TreeNode* root2)
    {
        if(root1 == NULL && root2 == NULL)
            return true;
        
        if(root1 == NULL || root2 == NULL)
            return false;
        
        if(root1->val != root2->val)
            return false;
        
        return (tru(root1->left,root2->right) && tru(root1->right,root2->left));
        
    }
    
    bool isSymmetric(TreeNode* root) {
        if(tru(root,root))
            return true;
        else
            return false;
        
    }
};
