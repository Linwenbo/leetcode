/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* reverseList(struct ListNode* head){
    if(!head) return head;
    struct ListNode *curr=head,*pnext=NULL,*pre=NULL;
    while(curr){
        pnext=curr->next;
        curr->next=pre;
        pre=curr;
        curr=pnext;
    }
    head=pre;
    return head;
}


