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
    int n ;
    
    int rightId(int val , int start , int end ,  vector<int>& preorder){
        for(int i = start ; i<=end ; i++){
            if(val < preorder[i])return i ;
        }
        return -1 ;
    }
    
    int leftId(int val , int start , int end ,  vector<int>&preorder){
        for(int i = start ; i<= end ; i++){
            if(val > preorder[i])return i ;
        }
        return -1 ;
    }
    
    void buildBst(TreeNode** root , int lo , int hi , vector<int>&preorder){
        if(lo>hi)return ;
        
        int Rid = rightId((*root)->val , lo , hi ,  preorder) ;
        int Lid = leftId((*root)->val , lo , (Rid==-1) ? hi : Rid-1 , preorder) ;
        
        if(Lid!=-1){
            (*root)->left = new TreeNode(preorder[Lid]) ;
            buildBst(&(*root)->left , Lid+1 , (Rid==-1) ? hi : Rid-1 , preorder) ;
        }
        
        if(Rid!=-1){
            (*root)->right = new TreeNode(preorder[Rid]) ;
            buildBst(&(*root)->right , Rid+1 , hi , preorder) ;
        }
        
    }
    
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        n = preorder.size() ;
        if(n==0)return NULL ;
        
        TreeNode *root = new TreeNode(preorder[0]) ;
        buildBst(&root, 1 , n-1 , preorder) ;
        return root ;
    }
};