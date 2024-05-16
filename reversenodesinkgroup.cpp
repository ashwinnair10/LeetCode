class Solution {
public:
    ListNode* recur(ListNode* head,int k){
        ListNode* temp=head;
        int c=0;
        while(temp!=nullptr){
            c++;
            temp=temp->next;
        }
        if(c<k)
        return head;
        ListNode* prev=nullptr;
        ListNode* curr=head;
        ListNode* next=curr->next;
        c=0;
        while(c<k){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
            c++;
        }
        if(next!=nullptr){
            ListNode* temp=recur(next,k);
            head->next=temp;
        }
        return prev;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        return recur(head,k);
    }
};