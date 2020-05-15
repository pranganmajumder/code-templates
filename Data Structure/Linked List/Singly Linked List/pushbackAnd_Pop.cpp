#include<bits/stdc++.h>
using namespace std ;


struct node{
    int value ;
    node *next ;
};

node *root = NULL ;

void PushBack(int v) // O(N) complexity
{
    if(root == NULL)
    {
        root = new node() ;
        root->value = v ;
        root->next = NULL;
    }
    else{
        node *currNode = new node() ;
        currNode = root ;
        while(currNode->next != NULL)
        {
            currNode = currNode->next ;
        }
        node *newNode = new node() ;
        newNode->value = v ;
        newNode->next = NULL ;
        currNode->next = newNode ;

        //delete(newNode) ; // ata deya zabe na ,, dile newNode ar sob  haray zabe current->next theke
    }
}


void printList()
{
    node *currNode = new node() ;
    currNode = root ;
    while(currNode->next != NULL)
    {
        cout << currNode->value << ' ' ;
        currNode = currNode->next ;
    }
    cout << currNode->value << endl ;

}



void POP(int v) // first theke zei node ar value v  sei node delete kore dite hobe
{
    node *currNode = new node() ;
    node *prevNode = new node() ;
    currNode = root ;

    while(currNode->value != v){
        prevNode = currNode ;
        currNode = currNode->next ;
    }

    if(currNode == root){ // root node hole 
        root = root->next ;
        delete(currNode) ;
    }
    else{
        prevNode->next = currNode->next ;
        delete(currNode) ;
    }
}

int main()
{
    int n ;
    cin >> n ;
    for(int i = 1 ; i<=n ; i++){
        int x ; cin >> x ;
        PushBack(x) ;
    }

    cout << "Printing Linked List element   " ;
    printList() ;

    while(cin >> n ){
        POP(n) ;
        cout << "after poping Printing List element  " ;
        printList() ;
    }

}
