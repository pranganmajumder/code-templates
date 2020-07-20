
//link : https://leetcode.com/explore/challenge/card/july-leetcoding-challenge/546/week-3-july-15th-july-21st/3396/

// another Ac Submission : https://paste.ubuntu.com/p/Zgj6QCRhjm/

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
    ListNode* removeElements(ListNode* head, int val) {
        
        while(head && head->val == val)head = head->next ;
        ListNode *prevNode , *currNode = head ;
        
        while(currNode){
            if(currNode->val == val)
                prevNode->next = currNode->next ;  
            else
                prevNode = currNode ;
            
            currNode = currNode->next ;
        }
        return head ;
    }
};