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
    int kthSmallest(TreeNode* root, int k) {
        vector<int>element ;
        queue<TreeNode*>Q ;
        Q.push(root) ;
        while(!Q.empty()){
            TreeNode* u = Q.front() ;
            element.push_back(u->val) ;
            Q.pop() ;
            if(u->left != NULL)Q.push(u->left) ;
            if(u->right!= NULL)Q.push(u->right) ;
        }
        sort(element.begin(),element.end()) ;
        return element[k-1] ;
    }
};