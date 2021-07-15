// By Chandramani Kumar
// Keep moving and must be simple bro!!!!!
// Espérons le meilleur mais préparez-vous au pire 😎


/* Problem Statement :

Given the root of a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

 
Example 1:

Input: root = [1,2,3,null,5,null,4]
Output: [1,3,4]

Example 2:

Input: root = [1,null,3]
Output: [1,3]

Example 3:

Input: root = []
Output: []
 

Constraints:

The number of nodes in the tree is in the range [0, 100].
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
    void rightSideView_help(TreeNode* A, int lvl, vector<pair<int,int> > &v)
    {
        if(A == NULL)
        return;

        v.push_back(make_pair(A->val, lvl));
        rightSideView_help(A->left, lvl + 1, v);
        rightSideView_help(A->right, lvl + 1, v);   
    }
    
    vector<int> rightSideView(TreeNode* A) {
        //vector<vector<int> > res1;
        
        if(A == NULL)
        return {};

        vector<pair<int,int> > v;

        rightSideView_help(A, 0, v);

        int n = v.size();
        int maxm = INT_MIN;

        for(int i=0;i<n;i++)
        {
            maxm = max(maxm, v[i].second);
        }

        vector<vector<int> > res(maxm+1);

        for(int i=0;i<n;i++)
        {
            res[v[i].second].push_back(v[i].first);
        }
        
        vector<int> ans;
        
        for(int i=0;i<res.size();i++)
        {
            ans.push_back(res[i][res[i].size()-1]);
        }
        
        return ans;
    }
};
