//problem link : https://leetcode.com/problems/sum-of-left-leaves/




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
    
    int fun(TreeNode* root, int flag){
        if(!root->left && !root->right && !flag)return root->val;
        
        int sum = 0;
        if(root->left)sum+=fun(root->left, 0);
        if(root->right)sum+=fun(root->right,1);
        return sum ;
    }
    
    int sumOfLeftLeaves(TreeNode* root) {
        if(root==NULL || (!root->left&&!root->right) )return 0;
        return fun(root,0) ;
    }
};