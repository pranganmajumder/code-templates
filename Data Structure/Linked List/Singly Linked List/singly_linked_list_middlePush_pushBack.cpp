#include<bits/stdc++.h>
using namespace std ;


struct node{
    int value ;
    node *next ;
};
node *root = NULL ;


void PushBack(int v)
{
    if(root == NULL){
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
    }
}

void middlePush(int value1 , int value2)
{
    //push value2 before value1
    node *currNode = new node() ;
    currNode = root ;
    while(currNode->value != value1){
        currNode = currNode->next ;
        if(currNode->next == NULL)return ; // zodi value1 na thake list a tobe
                                            // akhan thekei return kore dibe
    }

    node *newNode = new node() ;
    newNode->value = value2 ;
    newNode->next = currNode->next ;
    currNode->next = newNode ;

}

void printList()
{
    node *currNode = root ;
    while(currNode->next != NULL)
    {
        cout << currNode->value << ' ' ;
        currNode = currNode->next ;
    }
    cout << currNode->value << endl ;
}

int main()
{

    int n ;
    cin >> n ;
    for(int i =1 ; i<= n ;i++){
        int x ; cin >> x ;
        PushBack(x) ;
    }
    cout << "printing  List element   " ;
    printList() ;

    middlePush(3 , 5) ; // prothom zekhane 3pabe tar porei 5push hobe
    cout << "after push  5 " << endl ;
    printList() ;

    middlePush(7 , 100); // prothom zekhane 7 pabe tar porei 100 push hobe
    cout << "after push 100  " << endl;
    printList() ;

    middlePush(90 , 8);
    cout << "after push 8" << endl ;
    printList() ;
}


/*

9
1 4 6 3 7 6 3 7 9

*/
