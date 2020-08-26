
//link : https://leetcode.com/explore/challenge/card/july-leetcoding-challenge/547/week-4-july-22nd-july-28th/3398/


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

    
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root == NULL)return {} ;
        
        vector<vector<int> > ans ;
        vector<pair<int,int>> vec ;
        queue<pair<TreeNode* , int > > Q ;
        
        
        
        Q.push({root , 1}) ;
        while(!Q.empty()){
            pair<TreeNode* , int > v = Q.front() ;
            Q.pop() ;
            vec.push_back({v.first->val , v.second}) ;             // value , level 
            
            if(v.first->left)Q.push({v.first->left , v.second+1}) ;
            if(v.first->right)Q.push({v.first->right , v.second+1}) ;
        }
        vec.push_back({99999999 , 99999999}) ; // consecutive similar gula ak group , tai last a just append kore dilam 
        
        
        vector<int>v ;
        for(int i = 0 , ck = 1 ; i<vec.size()-1 ; i++ , ck++ ){//1 , 2 , 2 , 3 , 3 ,3 , 999999.
            while(vec[i].second == vec[i+1].second){
                v.push_back(vec[i].first) ;
                i++ ;
            }
            v.push_back(vec[i].first) ;
            if(ck % 2 == 0)reverse(v.begin() , v.end()) ; // direction change 
            ans.push_back(v) ;
            v.clear() ;
        }
        
        return ans ;
    }
};