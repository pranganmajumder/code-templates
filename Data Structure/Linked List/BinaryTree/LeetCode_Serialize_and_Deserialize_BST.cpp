//problem lInk : https://leetcode.com/problems/serialize-and-deserialize-bst/



/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    
    int toNum(string st){
        stringstream ss(st);
        int num ;
        ss>>num ;
        return num ;
    }
    
    //preOrder Traversal
    void preOrder(TreeNode* root , string& data){
        data+=to_string(root->val) + ' ' ;
        if(root->left == NULL && root->right == NULL)return ;
        
        if(root->left)preOrder(root->left , data);
        if(root->right)preOrder(root->right, data) ;
    }
    
    
    //make Binary Search Tree from preOrder Traversal array num
    void makeBST(TreeNode** root,vector<int>&num , int first, int last){ // here root address was sent through address
        (*root) = new TreeNode(num[first]) ; // as address was sent so you should write (*root)
        if(first == last)return ;
        
        int greaterId = -1 ;
        for(int i=first+1 ; i<=last ; i++){
            if( (*root)->val < num[i]){       // access using a '*' , cz it was sent through memory address
                greaterId = i ; break ;
            }
        }
        
        if(greaterId != -1){
            makeBST( &(*root)->right, num, greaterId, last) ; // make Right subtree & send node memory address
            if(first+1 <= greaterId-1)
                makeBST( &(*root)->left, num, first+1, greaterId-1) ; // make Left subtre & send node memory address
        }
        else{
            (*root)->right = nullptr ;
            if(first+1 <= last)
                makeBST( &(*root)->left , num, first+1 , last) ; // make left subtree & send node memory address
        }
    }
    
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root == nullptr)return "";
        string data = "" ;
        preOrder(root, data) ;
        return data ;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data == "")return nullptr;
        vector<int>numbers ;
        string st = "" ;
        for(int i=0, len = data.size() ; i<len ; i++){
            st = "" ;
            while(i<len && data[i] != ' ')
                st+=data[i++] ;
            if(st.size())numbers.push_back(toNum(st)) ;
            
        }
        
        
        TreeNode* root ;
        makeBST(&root , numbers,  0, numbers.size()-1) ; // send node address
        return root ;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;