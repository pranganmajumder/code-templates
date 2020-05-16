
// problem link : https://leetcode.com/problems/odd-even-linked-list/


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    
    
    ListNode* oddEvenList(ListNode* head) {
        ListNode* oddInit = new ListNode(-1) ; // initial odd 
        ListNode* evenInit = new ListNode(-1) ; // initial even
        ListNode* currNode = head , *currOdd = oddInit , *currEven = evenInit ;
        
        int cnt = 1 ; 
        while(currNode!=nullptr){
            if(cnt&1){
                currOdd->next = currNode ;
                currOdd = currOdd->next ; // currOdd = currNode dileo hobe
            }else{
                currEven->next = currNode ;
                currEven = currEven->next ; // currEven = currNode dileo hobe
            }
            currNode = currNode->next ;
            cnt++ ;
        }
        currEven->next = nullptr ;
        currOdd->next = evenInit->next ;
        head = oddInit->next ;
        
        return head ;
    }
};