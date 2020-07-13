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
    
    vector<int> Traverse(TreeNode* p){
        vector<int>v ;
        queue<TreeNode*>Q ;
        Q.push(p) ;
        v.push_back(p->val) ; // push the root Node value at first
        
        while(!Q.empty()){
            TreeNode* u = Q.front() ;
            Q.pop() ;
        
            if(u->left == NULL)v.push_back(0) ;
            else {
                v.push_back(u->left->val) ;
                Q.push(u->left) ;
            }
            
            if(u->right == NULL)v.push_back(0) ;
            else {
                v.push_back(u->right->val) ;
                Q.push(u->right) ;
            }
        }
        
        return v ;
    }
    
    bool isSameTree(TreeNode* p, TreeNode* q) {
        vector<int>first , second ;
        if(p!=NULL) first  = Traverse(p) ;
        if(q!=NULL) second = Traverse(q) ;
        
        return first == second ;
    }
};