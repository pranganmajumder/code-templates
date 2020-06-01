
// link === >>  https://leetcode.com/explore/challenge/card/june-leetcoding-challenge/539/week-1-june-1st-june-7th/3347/

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
    TreeNode* invertTree(TreeNode* root) {
        if(root==NULL)return root ;
        queue<TreeNode*>Q ; // pointer type 
        Q.push(root) ;
        while(!Q.empty()){
            TreeNode* u = Q.front() ; // pointer type
            Q.pop() ;
            swap(u->left , u->right) ;
            if(u->left != NULL)Q.push(u->left) ;
            if(u->right != NULL)Q.push(u->right) ;
        }
        return root ;
    }
};