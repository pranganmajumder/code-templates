// problem link : https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/




/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

/*
1)find postorder array last element's postion from 
inorder array. (cz it is the root for that subtree)


2) divide inorder array & postorder array 

thus way bulid every subtree 

for a specific subtree 
inorder first index = infirst
inorder last index = inLast 
postorder first index = pofirst
postorder last index = poLast 
how many element should take from both postorder first index can 
be calculate using Cnt ;

*/


TreeNode* createNode(int v){
    TreeNode* t = new TreeNode(v) ;
    return t ;
}

class Solution {
public:
    map<int,int>pos ;
    
TreeNode* fun(int infirst,int inLast, int pofirst,int poLast, vector<int>& inorder, vector<int>& postorder ){
        if(infirst>inLast)return nullptr ;
        if(infirst == inLast)return createNode(inorder[inLast]) ;
    
        int p = pos[postorder[poLast]] , cnt = p-infirst ;
        TreeNode* temp = createNode(postorder[poLast]) ;
        temp->left = fun(infirst,p-1,pofirst,pofirst+cnt-1, inorder,postorder);
        temp->right = fun(p+1,inLast,pofirst+cnt,poLast-1, inorder,postorder) ;
        return temp ;
}
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.size()==0)return nullptr ;
        for(int i=0;i<inorder.size();i++)
            pos[inorder[i]]=i ;
        return fun(0,inorder.size()-1, 0, postorder.size()-1 , inorder, postorder) ;
    }
};