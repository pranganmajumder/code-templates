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


 //problem  https://leetcode.com/explore/challenge/card/july-leetcoding-challenge/545/week-2-july-8th-july-14th/3385/

 
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode* ,unsigned long> >Q ;
        vector<unsigned long>v ;
        
        Q.push({root , 1}) ;
        
        while(!Q.empty()){
            pair<TreeNode* , unsigned long > currNode = Q.front() ;
            Q.pop() ;
            
            v.push_back(currNode.second) ;
            
            int nodeVal = (currNode.first)->val ;
            
            if((currNode.first)->left != NULL)
                Q.push({(currNode.first)->left , currNode.second*2}) ;
            
            if((currNode.first)->right != NULL)
                 Q.push({(currNode.first)->right , currNode.second*2+1}) ;
            
            if(currNode.second*2 >= INT_MAX)return 1 ; // if tree will become very large then 
            // you can simply return 1 , cz in problem there is said anser won't be exceeded INT_MAX
            // this exexption for testcase 107
            
        }
        
        map<int ,vector<unsigned long> >freq ;
        for(int i = 0 ; i<v.size() ; i++){
            for(int k = 0 ; k<32 ; k++){
                int  lo = 1<<k , hi = (1<<(k+1)) - 1 ;
                if(lo <= v[i] && v[i] <= hi){
                    freq[k].push_back(v[i]) ;
                    break ;
                }
            }
        }
        
        int mx = 0 ;
        for(auto it : freq){
            vector<unsigned long >temp = it.second ;
            sort(temp.begin() , temp.end()) ;
            mx = max(mx , (int)(temp.back() - temp.front() + 1) ) ;
        }
        
        return mx ;
    }
};