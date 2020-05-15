#include<bits/stdc++.h>
using namespace std ;
// https://ideone.com/GNrxwz

struct ListNode{
    int data ;
    ListNode *next ;
    ListNode(){} ; // default constructor na dile "new ListNode()" kaj korbe na 
    ListNode(int x): data(x) , next(NULL){}; 
};


//O(1) complexity if use a tail pointer 
void PUSH(ListNode** head , ListNode** tail , int data_)
{
    ListNode *newNode = new ListNode() ; // create a new node
    newNode->data = data_ ;
    newNode->next = NULL ;

    if(*head == NULL){
        *head = newNode ;
        *tail = *head ; // (here i used"*"" before "tail" & "head")
    }
    else{
        (*tail)->next = newNode ; //here also 
        *tail = newNode ; // here also
    }

}

/**
O(N) complexity if i don't use tail pointer 
void PUSH(ListNode** head , int data_) // here ** with head
{
    if( *head == NULL ){ // here you have to use *head 
        ListNode *newNode = new ListNode() ;
        newNode->data = data_ ;
        newNode->next = NULL ;
        (*head) = newNode ; // ahaneo * dite hobe
    }
    else{
        ListNode *currNode = *head ; // here * before head
        while (currNode->next != NULL)
        {
            currNode = currNode->next ;
        }
        ListNode *newNode = new ListNode() ;
        newNode->data = data_ ;
        newNode->next = NULL ;
        currNode->next = newNode ;
    }
}

**/

void prin(ListNode* head)
{
    ListNode *currNode = head ;
    while (currNode->next != NULL)
    {
        cout << currNode->data << ' ' ;
        currNode = currNode->next ;
    }
    cout << currNode->data;
    cout << endl ;  
    
}

int main()
{
    int n , x ;
    cin >> n ;
    ListNode *head = NULL , *tail = NULL ;
    for(int i = 1 ; i<=n ; i++){
        cin >> x ;
         PUSH(&head , &tail ,  x) ; // here pointer ar address send korchi
    }
    cout << "tail data  =  " << tail->data << endl ;
    cout << "head data  =  " << head->data << endl ;
    prin(head) ;
}