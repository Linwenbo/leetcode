/**
 * You are given two non-empty linked lists representing two non-negative integers.
 * The digits are stored in reverse order and each of their nodes contain a single digit. 
 * Add the two numbers and return it as a linked list.
 * You may assume the two numbers do not contain any leading zero, except the number 0 itself
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    int carry=0;
    struct ListNode *result,*tmp;
    tmp=(struct ListNode*)malloc(sizeof(struct ListNode));
    result=tmp;
    tmp->next=NULL;
    while(true) {
        if(!l1&&!l2) break;
        if(!l1) {
            tmp->val=(l2->val+carry)%10;
            carry=((l2->val+carry)>=10);
            l2=l2->next;
        } 
        else if(!l2) {
            tmp->val=(l1->val+carry)%10;
            carry=((l1->val+carry)>=10);
            l1=l1->next;
        }
        else {
            tmp->val=(l1->val+l2->val+carry)%10;
            carry=((l1->val+l2->val+carry)>=10);
            l1=l1->next;
            l2=l2->next;
        }
        if(l1||l2) {
            tmp->next=(struct ListNode*)malloc(sizeof(struct ListNode));
            tmp=tmp->next;
            tmp->next=NULL;
        }      
    }
    if(carry) {
        tmp->next=(struct ListNode*)malloc(sizeof(struct ListNode));
        tmp=tmp->next;
        tmp->next=NULL;
        tmp->val=1;
    }
    return result;
}
