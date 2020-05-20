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
    ListNode*root ;
    
    void fun(ListNode* parNode , ListNode* currNode){
        if(currNode == NULL) {root = parNode ; return ;}
        fun(currNode , currNode->next) ;
        currNode->next = parNode ;
    }
    
    ListNode* reverseList(ListNode* head) {
        fun(NULL , head) ;
        return root ;
    }
};