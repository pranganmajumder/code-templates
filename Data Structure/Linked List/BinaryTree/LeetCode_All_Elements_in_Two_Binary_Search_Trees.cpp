// link : https://leetcode.com/problems/all-elements-in-two-binary-search-trees/




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
    
    void traverseTree(TreeNode* root, vector<int>&v){
        v.push_back(root->val);
        if(!root->left && !root->right) return;
        if(root->left)traverseTree(root->left, v);
        if(root->right)traverseTree(root->right,v);
    }
    
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        if(root1==nullptr && root2==nullptr)return {};
        vector<int>v;
        
        if(root1)traverseTree(root1, v);
        if(root2)traverseTree(root2, v);
        sort(v.begin(),v.end());
        return v;
    }
};