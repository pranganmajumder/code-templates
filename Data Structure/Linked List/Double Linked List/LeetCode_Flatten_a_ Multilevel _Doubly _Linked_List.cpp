
// https://leetcode.com/explore/challenge/card/july-leetcoding-challenge/545/week-2-july-8th-july-14th/3386/


/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

Node* createNode(int v){
    Node* temp = new Node() ;
    temp->val = v ;
    temp->prev = NULL ;
    temp->next = NULL ;
    temp->child = NULL ;
    
    return temp ;
}

class Solution {
public:
    
    
     // void printList(Node* root){
    //     Node* currNode = root ;
    //     while(currNode != NULL){
    //         cout << currNode->val << endl ;
    //         currNode = currNode->next ;
    //     }
    // }
    
    vector<int>v ;
    void fun(Node* head){
        if((head) == NULL)return ;
        v.push_back(head->val) ;
        
        fun((head)->child) ;
        fun((head)->next) ;
    }
    
    Node* flatten(Node* head) {
        if(head == NULL)return head ;
        fun(head) ; // traverse the list At first and store all the value in a vector 
        
        Node* root = createNode(v[0]) , *currNode = root , *prevNode = root ; 
        for(int  i = 1 ; i<v.size() ; i++){ // Now create doubly Linked list using vector value
            currNode = createNode(v[i]) ;
            prevNode->next = currNode ;
            currNode->prev = prevNode ;
            prevNode = currNode ;
        }
        return root ;
    }
};