class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* head=nullptr;
        ListNode* temp=nullptr;
        ListNode* t1=list1;
        ListNode* t2=list2;
        while(t1!=nullptr&&t2!=nullptr){
            if(t1->val<t2->val){
                if(head==nullptr){
                    head=new ListNode(t1->val);
                    temp=head;
                }
                else{
                    temp->next=new ListNode(t1->val);
                    temp=temp->next;
                }
                t1=t1->next;
            }
            else{
                if(head==nullptr){
                    head=new ListNode(t2->val);
                    temp=head;
                }
                else{
                    temp->next=new ListNode(t2->val);
                    temp=temp->next;
                }
                t2=t2->next;
            }
        }
        if(t1!=nullptr){
            if(head==nullptr)
            head=t1;
            else
            temp->next=t1;
        }
        if(t2!=nullptr){
            if(head==nullptr)
            head=t2;
            else
            temp->next=t2;
        }
        return head;
    }
};