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
    
// get min & max for left tree
// get min & max for right tree
    
// max of left subtree  < root->val ( L.second < root->val )

// min of right subtree > root->val ( root->val < R.first )




public:
    
    bool flag = true ;
    
    pair<int,int> fun(TreeNode* root){
        
        if(!root->left && !root->right)
            return {root->val, root->val};
        else if(root->left && root->right){
            pair<int,int> L = fun(root->left);
            pair<int,int> R = fun(root->right);
            if(L.second < root->val && root->val < R.first)
                return {min(root->val , L.first) , max(root->val, R.second)};
            else {
                flag = false ;
                return {min(root->val , L.second) , max(root->val, R.second)};
            }
        }
        else if(root->left){
            pair<int,int> L = fun(root->left) ;
            if(L.second < root->val)return {min(root->val, L.first) , root->val} ;
            else{
                flag = false ;
                return {0, 0};
            }
        }
        else {
            pair<int,int> R = fun(root->right);
            if(root->val < R.first)return {min(root->val, R.first), R.second};
            else {
                flag = false ;
                return {0,0};
            }
        }
        
        
        
    }
    
    bool isValidBST(TreeNode* root) {
        if(root == nullptr)return true;
        pair<int,int> res = fun(root) ;
        return flag;
    }
};
