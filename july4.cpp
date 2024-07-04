class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        ListNode* root=nullptr;
        ListNode* temp;
        while(head!=nullptr){
            if(head->val==0&&head->next!=nullptr){
                temp=head;
                if(root==nullptr){
                    root=temp;
                }
                head=head->next;
                if(head==nullptr)
                break;
                while(head->val!=0){
                    temp->val+=head->val;
                    head=head->next;
                }
                temp->next=head;
            }
            else if(head->val==0&&head->next==nullptr){
                head=head->next;
            }
        }
        temp->next=nullptr;
        return root;
    }
};