class Solution {
public:
    ListNode* doubleIt(ListNode* head) {
        ListNode* tail=nullptr;
        int c=0;
        ListNode* current = head;
        ListNode* prev = NULL;
        ListNode* next = NULL;
        while (current != NULL) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        head = prev;
        ListNode* temp=head;
        while(temp!=nullptr){
            int s=(2*temp->val+c);
            c=s/10;
            temp->val=s%10;
            if(temp->next==nullptr){
                tail=temp;
            }
            temp=temp->next;
        }
        if(c){
            tail->next=new ListNode(1);
        }
        current = head;
        prev = NULL;
        next = NULL;
        while (current != NULL) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        head = prev;
        return head;
    }
};