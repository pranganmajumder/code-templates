
#include<bits/stdc++.h>
using namespace std ;


struct node{
    int v ;
    node *next ;
};



node* PUSH(int x , node* head) // O(N) complexity 
{
    if(head == NULL){
        head = new node() ;
        head->v = x ;
        head->next = NULL ;
    }
    else{
        node *currNode = head ;
        while(currNode->next != NULL){
            currNode = currNode->next ;
        }
        node *newNode = new node() ;
        newNode->v = x ;
        newNode->next = NULL ;

        currNode->next = newNode ;
    }
    return head ;
}


node* tail = NULL ;
node* PUSH_O_1(int x , node* head) // O(1) complexity 
{
    node* newNode = new node() ;
    newNode->v = x ;
    newNode->next = NULL ;

    if(head==NULL){
        head = newNode ;
        tail = head ;
    }else{
        tail->next = newNode ;
        tail = tail->next ;
    }
    
    return head ;
}


int lenList(node* head) // it will find linked list length , ata obosso O(1) kora zay push ar somoy counter variable dia 
{
    int cnt = 1 ;
    node* currNode = new node() ;
    currNode = head ;
    while(currNode->next != NULL){
        cnt++ ;
        currNode = currNode->next ;
    }
    return cnt ;
}





void prin(node* head)
{
    node *currNode = head ;
    while(currNode->next != NULL){
        cout << currNode->v << ' ' ;
        currNode = currNode->next ;
    }
    cout << currNode->v << endl ;

}

int main()
{
    int n ;
    node *head = NULL  ;
    cin >> n ;
    for(int i = 1 ; i<=n ; i++){
        int x ; cin >> x ;
        //head = PUSH(x , head) ;
        head = PUSH_O_1(x,head) ;
    }

    //cout << head->v << ' ' << head->next << endl ;
    prin(head) ;
    
    
    
    int len = lenList(head) ;
    cout << "len  " << len << endl ;
}
