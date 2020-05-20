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
    map<int,int>par , depth ;
    
    void TraverseBinaryTree(TreeNode** root , int d ){
        if((*root) == NULL)return ;
        depth[(*root)->val] = d ;
        par[(*root)->left] = par[(*root)->right] =  (*root)->val ;
        
        TraverseBinaryTree(root->left , d+1 ) ;
        TraverseBinaryTree(root->right , d+1 ) ;
    }
    
    bool isCousins(TreeNode* root, int x, int y) {
        TraverseBinaryTree(&root , 0) ;
        return (par[x] != par[y] && depth[x] == depth[y]) ;
    }
};