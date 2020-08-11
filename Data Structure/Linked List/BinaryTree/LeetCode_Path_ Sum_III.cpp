//problem link : https://leetcode.com/explore/challenge/card/august-leetcoding-challenge/550/week-2-august-8th-august-14th/3417/
// or direct problem link => https://leetcode.com/problems/path-sum-iii/





/*
another solution : 
    1)tutorial https://www.youtube.com/watch?v=Nd1X65PQgmE&feature=youtu.be
        https://paste.ubuntu.com/p/TbwCGgQBGg/
    
*/



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
    
    int tot = 0 ;
    
vector<int> dfs(TreeNode* root , int sum){
                if(root->left == nullptr && root->right == nullptr){
                    if(root->val == sum)tot++ ;
                    return {root->val} ;
                }

                vector<int>left , right , v ;
                v.push_back(root->val) ;
    
                if(root->left){
                    left = dfs(root->left , sum) ;
                    for(int a : left)v.push_back(root->val+a) ;
                }

                if(root->right){
                    right = dfs(root->right, sum) ;
                    for(int a : right)v.push_back(root->val+a) ;
                }
    
                for(int a : v)
                    if(a==sum)tot++ ;
                
                return v ;
            }
    
    int pathSum(TreeNode* root, int sum) {
        if(root==nullptr)return 0;
        vector<int>v = dfs(root, sum) ;
        return tot ; 
    }
};
