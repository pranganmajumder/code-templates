
//link  https://leetcode.com/explore/challenge/card/30-day-leetcoding-challenge/530/week-3/3305/
// this is another solution      https://paste.ubuntu.com/p/m8P32nz97f/

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
    
    // TreeNode* createNode(int data_){
    //     TreeNode* newNode = new TreeNode() ;
    //     newNode->val = data_ ;
    //     newNode->left = newNode->right = NULL ;
    //     return newNode ;
    // }
    int searchBig(int val , vector<int>&preorder ,  int start , int End){
        for(int i = start ; i <= End ; i++){
            if(val < preorder[i])return i ;
        }
        return -1 ;
    }
    
    int searchSmall(int val , vector<int>&preorder , int start , int End){
        for(int i = start ; i<= End ; i++){
            if(preorder[i] < val )return i ;
        }
        return -1 ;
    }
    
    void make_bst(TreeNode** parent , vector<int>&preorder ,  int start , int End ){
        int bId = searchBig( (*parent)->val , preorder , start , End) ;
        int cId = searchSmall((*parent)->val , preorder, start , End) ;
        
        if(bId == -1){
            ;
        }
        else{
            TreeNode* newNode = new TreeNode(preorder[bId]) ;
            (*parent)->right = newNode ;
            make_bst(&(*parent)->right , preorder , bId+1 , End) ;
        }
        
        if(cId == -1){
            ; 
        }
        else{
            TreeNode* newNode = new TreeNode(preorder[cId]) ;
            (*parent)->left = newNode ;
            int temp = (bId == -1) ? End : bId-1 ;
            make_bst(&(*parent)->left , preorder , start+1 ,  temp ) ;
        }
    }
    
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode *root = new TreeNode(preorder[0]) ;
        make_bst(&root , preorder , 1 , preorder.size()-1) ; // send address of pointer
        return root ;
    }
};
