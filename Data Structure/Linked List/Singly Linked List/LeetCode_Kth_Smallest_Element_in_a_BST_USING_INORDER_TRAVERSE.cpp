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

    vector<int>element ;
    void inOrderTraverse(TreeNode* root){
        if(root == NULL)return ;
        
        if(root->left)inOrderTraverse(root->left) ;
        element.push_back(root->val) ;
        if(root->right)inOrderTraverse(root->right) ;
    }
    
    int kthSmallest(TreeNode* root, int k) {
        inOrderTraverse(root) ;
        return element[k-1] ;
    }
};