// link : https://leetcode.com/problems/binary-tree-level-order-traversal-ii/



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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if(!root)return {} ;
        
        queue<pair<TreeNode* , int> >Q ;
        vector<vector<int> >res ;
        
        
        Q.push({root , 1}) ; // node , level 
        vector<pair<int , int>> vec ;
        
        
        while(!Q.empty()){
            pair<TreeNode*,int> v = Q.front() ;
            Q.pop() ;
            vec.push_back({v.first->val , v.second}) ;
            
            if(v.first->left)Q.push({v.first->left , v.second+1}) ;
            if(v.first->right)Q.push({v.first->right , v.second+1}) ;
        }
        vec.push_back({99999 , -1}) ;   
        
        vector<int>temp ;
        int flag = 0 ;
        for(int i = 0 ; i<vec.size() ; i++){
            if(flag != vec[i].second){
                if(temp.size())
                    res.push_back(temp) ;
                temp.clear() ;
                flag = vec[i].second ;
            }
            temp.push_back(vec[i].first) ;
        }
        
        reverse(res.begin() , res.end()) ;
        return res ;
    }
};