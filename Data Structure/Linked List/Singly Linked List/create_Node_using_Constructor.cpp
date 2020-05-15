#include<bits/stdc++.h>
using namespace std ;


struct ListNode{
    int data ;
    ListNode *next ;
    ListNode(){} ; // default constructor na dile "new ListNode()" kaj korbe na 
    ListNode(int x): data(x) , next(NULL){} // parameterized constructor
};


ListNode* createNode(int __data)
{
    ListNode* newNode = new ListNode() ;
    newNode->data = __data ;
    newNode->next = NULL ;
    return newNode ;
}

ListNode* createNode_2(int __data)
{
    ListNode* newNode = new ListNode(__data) ;
    return newNode ;
}

void createNodeUsingAddress(ListNode** temp , int __data) // pointer address send korle avebe dite hoy
{
    (*temp) = new ListNode() ; // oi pointer address a new pointee set kore dite hoy 
    (*temp)->data = __data ;
    (*temp)->next = NULL ;
}

int main()
{

    int n ; 
    n = 1 ;
    ListNode newNode = ListNode(n) ;  // ata variable not pointer  tai new dei nai

    cout << "newNode data is  " << newNode.data  << endl ; // akhane "." dia access kora hoiche
                                                        // ata pointer type na


    // Method1 ==>> create a Node ;                                                   
    ListNode *currNode = new ListNode() ;
    currNode->data = n ;
    currNode->next = NULL ;

    cout << "currNode  data is  " << currNode->data << endl ; // -> dia access cz ata pointer type


    // Method2 ==>> create a Node using parameterized constructor
    ListNode * temp = new ListNode(2) ; // pointer hole new deya lagbe 
    cout << "temp  data  " << temp->data << endl ;
    cout << "temp next   "  << temp->next << endl ;


    // Method3  == >> create a Node using function
    ListNode* temp2 = createNode(3) ;
    cout << "temp2 data         " << temp2->data << endl ;
    cout << "temp2  next        " << temp2->next << endl ;    


    // Method4  == >> create a Node using funtion2 
    temp2 = createNode_2(4) ;
    cout << "temp2 data  another method        " << temp2->data << endl ;
    cout << "temp2  next  another method       " << temp2->next << endl ; 

    // Method5  == > create a Node sending address 
    ListNode* root ;
    //root = new ListNode() ;  ata dile 29 no line dite hobe na ar . 
    createNodeUsingAddress(&root , 5) ;
    cout << "\n\n using address  node value   " << root->data << endl ;
    cout << "using address node next          " << root->next << endl ;
                                                            
}