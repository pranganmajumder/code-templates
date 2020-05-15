/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//link  ::  https://leetcode.com/explore/challenge/card/30-day-leetcoding-challenge/529/week-2/3293/

class Solution {  
    
public:
    
    int mx = 0 ;
    
    int dfs(TreeNode* root)
    {
        if(root == NULL)return 0 ;
        int left = dfs(root->left) ;
        int right = dfs(root->right) ;
        mx = max(mx , left+right) ;
        return 1+max(left,right) ;
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        dfs(root) ;
        return mx ;
    }
};




