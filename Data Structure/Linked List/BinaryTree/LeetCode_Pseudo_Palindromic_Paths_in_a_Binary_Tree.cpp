// problem link : https://leetcode.com/problems/pseudo-palindromic-paths-in-a-binary-tree/

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
    
    void assistFunc(TreeNode* root, map<int,int>& mp, int& tot){
        if(!root->left && !root->right) {
            mp[root->val]++ ;
            int odd = 0 ;
            for(auto &it : mp)
                if(it.second & 1)odd++;
            if(odd <= 1)tot++;
            mp[root->val]-- ;
            
        }
        
        if(root->left){
            mp[root->val]++ ;
            assistFunc(root->left, mp, tot) ;
            mp[root->val]-- ;
        }
        if(root->right){
            mp[root->val]++ ;
            assistFunc(root->right, mp, tot) ;
            mp[root->val]-- ;
        }
    }
    
    int pseudoPalindromicPaths (TreeNode* root) {
        map<int,int>freq;
        int tot = 0 ;
        assistFunc(root, freq, tot) ;
        return tot;
    }
};
