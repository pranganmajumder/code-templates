
/**
 * https://www.geeksforgeeks.org/implementation-deque-using-doubly-linked-list/
 **/

#include<bits/stdc++.h>
using namespace std ;


struct ListNode{
    int data ;
    ListNode* prev , *next ;
    ListNode():data(0) , prev(nullptr) , next(nullptr){} 
    ListNode(int x):data(x) , prev(nullptr) ,  next(nullptr){}
    ListNode(int x , ListNode* ptr1 , ListNode* ptr2):data(x) , prev(ptr1) , next(ptr2) {} 
};
ListNode* head = NULL , *tail = NULL ;
int totSize = 0 ;


void PUSH_FRONT(int __data)
{
    ListNode* newNode = new ListNode(__data) ;
    if(head == NULL){
        head = newNode ; 
        tail = newNode ;
    }else{
        newNode->next = head ;
        head->prev = newNode ;
        head = newNode ;
    }
    totSize++ ;
}

void PUSH_BACK(int __data)
{
    ListNode* newNode = new ListNode(__data) ;
    if(head==NULL){
        head = newNode ;
        tail = newNode ;
    }else{
        tail->next = newNode ;
        newNode->prev = tail ;
        tail = newNode ;
    } 
    totSize++ ;  
}



void POP_FRONT()
{
    ListNode* tmp = head ;
    head = head->next ;        //head->next NULL hole head = NULL hoye zabe , mane tokhon deque empty 
    if(head==NULL)tail = NULL ;
    else head->prev = NULL ;
    delete(tmp) ;
    totSize-- ;
}

void POP_BACK()
{
    ListNode* tmp = tail ;
    tail = tail->prev ;       // tail->prev NULL hole tail = NULL hoye zabe , mane tokhn deque empty 
    if(tail==NULL)head = NULL ;
    else tail->next = NULL ;
    delete(tmp) ;
    totSize-- ;
}

bool isEmpty()
{  
    return (head == NULL) ;
}

int getFront()
{
    if(isEmpty())return -1 ;
    return head->data ;
}

int getBack()
{
    if(isEmpty())return -1 ;
    return tail->data ;
}

void printForword()
{
    ListNode* currNode = head ;
    while (currNode != NULL)
    {
        cout << currNode->data << " " ;
        currNode = currNode->next ;
    }cout << endl ;
}

void printBackword()
{
    ListNode* currNode = tail ;
    while (currNode != NULL)
    {
        cout << currNode->data << ' ' ;
        currNode = currNode->prev ;
    }cout << endl ;
}

void allClear()
{
    tail = NULL ;
    while (head!=NULL){
        ListNode* temp = head ;
        head = head->next ;
        delete(temp) ;
    }
    totSize = 0 ;
}

int main()
{
    int n , x , type ; 
    cout << "How many Element do you want to insert in  back   " ;
    cin >> n ;
    for(int i = 0 ; i<n ; i++){
        cin >> x ;
        PUSH_BACK(x) ;
    }

    cout << "How many Element do you want to insert in front   " ; 
    cin >> n ;
    for(int i = 0 ; i<n ; i++){
        cin >> x ;
        PUSH_FRONT(x) ;
    }

    cout << "total deque size is   " << totSize << endl << endl << endl ;

    cout << "NOW YOUR LIST ELEMENT IS   " ;
    printForword() ;

    cout << "\n\nHOW MANY POP operation DO YOU WANT TO execute   ??????     " ;
    cin >> n ;
    while (n--)
    {
        if(isEmpty()){
            cout << "OH NO YOUR LIST IS EMPTY" << endl; 
        }
        else{
            cout << "\n\nPlease enter type   " ;
            cin >> type ;
            if(type == 2){
                cout << "as type is 2 so the elements after POP from back  \n" ;
                POP_BACK() ;
            }
            else{
                cout << "as type is 1 so the elements after  POP from front  \n " ;
                POP_FRONT() ;
            }
            
            cout << "print from forward   " ;
            printForword() ;
            cout << "print from backward  " ;
            printBackword() ;
        }
    }
    
}

/**
4 
1 2 3 4
2
10 20
8
1 1 1 2 2 1 2 1
**/