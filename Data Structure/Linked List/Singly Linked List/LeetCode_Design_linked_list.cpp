// problem link :: https://leetcode.com/problems/design-linked-list/

#include<bits/stdc++.h>
using namespace std ;

class MyLinkedList {
public:
    /** Initialize your data structure here. */
    struct node{
      int data ;
        node* next ;
        node(){};
        node(int x) : data(x) , next(NULL){} ;
    };
    int len  ;   
    node* head , *tail  ;
    
    MyLinkedList() { // default constructor 
        len = 0 ;
        head = NULL , tail = NULL ;
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        if(head == NULL || index > len-1)return -1 ;
        node* currNode = head ;
        int cnt = 0 , val  ;
        while(currNode->next != NULL){ // last node hole loop a asbe na val , tai baire if diye 35 no line a  korchi oita 
            if(cnt == index){
                val = currNode->data ;
                break ;
            }
            currNode = currNode->next ;
            cnt++ ;
        }
        if(currNode->next == NULL){//last Node hole
            val = currNode->data ;
        }
        return val ;
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        node* newNode = new node(val) ;
        if(head == NULL){ // empty list hole head & tail ak e hobe
            head = tail = newNode ;
        }
        else{
            newNode->next = head ;
            head = newNode ;
        }
        len++ ;
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        node* newNode = new node(val) ;
        tail->next = newNode ;
        tail = newNode ;
        len++ ;
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        if(get(index) == -1 )return ;
        if(index == 0){// new node hobe head , index 0 mane list empty akbare , tai head atai hobe 
            node* newNode = new node(val) ;
            newNode->next = head ;
            head = newNode ;
            len++ ;
        }
        else if(index == len){// just add after tail(as all are 0 based )
            node* newNode =  new node(val) ;
            tail->next = newNode ;
            tail = newNode ;
            len++ ;
        }
        else if(index <= len-1){
            node* currNode = head , *newNode = new node(val) , *prev = new node() ;
            int cnt = 0;
            while(currNode->next != NULL){
                if(cnt == index){
                    newNode->next = currNode ;
                    prev->next = newNode ;
                    len++ ;
                    return ; // return or break deya lagbe 
                }
                prev = currNode ;
                currNode = currNode->next ;
                cnt++ ;
            }
            if(currNode->next == NULL){// length-1 a add hole
                newNode->next = currNode ;
                prev->next = newNode ;
                len++ ;
            }
        }
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if(get(index) != -1){
            if(len == 1 && index == 0){
                node* currNode = head ;
                head = tail = NULL ;
                len--;
                delete(currNode) ;
            }
            else if(len > 1 && index == 0 ){
                node* currNode = head ;
                head = head->next ;
                len--;
                delete(currNode) ;
            }
            else{
                node* currNode = head , *prev = new node() ;
                int cnt = 0 ;
                while(currNode->next != NULL){
                    if(cnt == index){
                        prev->next = currNode->next ;
                        len--;
                        delete(currNode) ;
                        return ; // return / break na dile RTE asbe 
                    }
                    prev = currNode ;
                    currNode = currNode->next ;
                    cnt++; 
                }
                if(currNode->next == NULL){ // zodi currNode last node hoy
                    prev->next = currNode->next ;
                    delete(currNode) ;
                    len--;
                    tail = prev ;
                }
            }
        }
    }


    void printList() // it was not included in the original problem , i added it for my own advantage
    {   cout << "print Lined List    "  ;
        node* currNode = head ;
        while (currNode->next != NULL)
        {
            cout << currNode->data << ' ' ;
            currNode = currNode->next ;
        }
        cout <<currNode->data << endl ;
        
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 * 
 * 
 *  Note  :::::     avabe hocche object ar pointer , ni ce main function ar moto nileo hobe 
 */



int main()
{
    MyLinkedList obj = MyLinkedList() ;
    int param_1 = obj.get(0) ;
    cout << param_1 << endl ;

    obj.addAtHead(10) ;
    cout << obj.get(0) << endl;
    obj.printList() ;
}
