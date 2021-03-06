
// problem Link : https://leetcode.com/problems/same-tree/
// another solution using BFS   https://paste.ubuntu.com/p/n2xxtzvN95/

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
    
    
    
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p && !q)return 1 ;   // p == NULL && q == NULL 
        
        if(p && q && p->val == q->val){    // p!=NULL && q!= NULL && p->val == q->val 
            return isSameTree(p->left , q->left) && isSameTree(p->right , q->right) ;   
        }
        else return false ;
    }
};