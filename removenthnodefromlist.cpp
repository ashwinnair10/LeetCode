class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int size=0;
        ListNode* temp=head;
        while(temp!=nullptr){
            size++;
            temp=temp->next;
        }
        n=size-n+1;
        temp=head;
        if(n==1)
        return head->next;
        while(temp!=nullptr){
            n--;
            if(n==1){
                temp->next=temp->next->next;
                break;
            }
            temp=temp->next;
        }
        return head;
    }
};