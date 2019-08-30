/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* rotateRight(struct ListNode* head, int k){
    if (!head) return head;
    
    int list_len = 0, rotate_cnt=k;
    struct ListNode *curr = head, *pnext=NULL, *end=NULL;
    while (curr){
        end=curr;
        curr=curr->next;
        list_len+=1;
    }
    end->next=head;    //make singly-linked list a circular singly-linked list
    rotate_cnt%=list_len;
    
    curr=head;
    while (list_len-rotate_cnt-1){   //after this, curr is the end node of new list;
        curr=curr->next;
        rotate_cnt+=1;
    }
    pnext=curr->next;
    curr->next=NULL;
    return pnext;
}
