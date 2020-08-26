//problem link : https://leetcode.com/problems/maximum-level-sum-of-a-binary-tree/



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
    
    void dfs(map<int,vector<int>>&fmap, TreeNode* root, int level){
        fmap[level].push_back(root->val);
        if(root->left)dfs(fmap, root->left, level+1);
        if(root->right)dfs(fmap, root->right, level+1);
    }
    
    int maxLevelSum(TreeNode* root) {
        if(root==nullptr)return 1;
        map<int,vector<int>>fmap;
        dfs(fmap, root,1);
        int mxSum = 0 , res = 1 ;
        for(auto it : fmap){
            int sum = 0 ;
            for(auto v : it.second)
                sum+=v;
            if(sum>mxSum)mxSum=sum, res=it.first;
        }
        return res ;
    }
};