/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {

    int carry=0;
    struct ListNode* temp=malloc(sizeof(struct ListNode));
    temp->next=NULL;
    struct ListNode* curr=temp;
    while(l1!=NULL ||l2!=NULL || carry){
        int l1_value=0;
        int l2_value =0;
        if(l1!=NULL){
            l1_value=l1->val;
            l1=l1->next;
        }
        if(l2!=NULL){
            l2_value=l2->val ;
            l2=l2->next;
        }
        int total=l1_value+l2_value+carry;
        carry=total/10;
        struct ListNode* newnode=malloc(sizeof(struct ListNode));
        newnode->val=total%10;
        newnode->next=NULL;
        curr->next=newnode;
        curr=curr->next;

    }
    return temp->next;
}