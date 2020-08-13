//problem link : https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/






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
    
    struct info{
      int val,x,t,y ;
      info(){};
      info(int val ,int y){
          this->val = val ;
          this->y = y ;
      }
      bool operator<(const info& s)const{
          if(y==s.y)return val<s.val ;
          return y>s.y ;
          
      }
      
    };
    
    // static bool cmp(info& s1 , info& s2){   // You can use it also but add "static" keyword before bool
    //     if(s1.y==s2.y)
    //         return s1.val<s2.val ;
    //     return s1.y > s2.y ;
    // }
    
    void recur(map<int,vector<info>>&mmap ,TreeNode* root , int xIndex , int yIndex){
        if(root==NULL)return ;
        mmap[xIndex].push_back(info(root->val,yIndex)) ;
        recur(mmap,root->left , xIndex-1, yIndex-1) ;
        recur(mmap,root->right, xIndex+1, yIndex-1) ;
    }
    
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        if(root==nullptr)return {} ;
        map<int,vector<info>>mmap ;
        vector<vector<int>>v ;
        recur(mmap,root,0, 0) ;
        
        for(auto it : mmap){
            vector<int>temp ;
            sort(it.second.begin() , it.second.end()) ;
            for(auto jt : it.second)
                temp.push_back(jt.val) ;
           
            v.push_back(temp) ;
        }
        return v ;
    }
};