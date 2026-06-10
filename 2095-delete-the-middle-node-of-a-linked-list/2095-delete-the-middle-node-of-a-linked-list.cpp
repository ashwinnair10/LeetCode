class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        int n=0;
        ListNode* root=head;
        while(root){
            n++;
            root=root->next;
        }
        ListNode* prev=nullptr;
        ListNode* curr=head;
        int mid=n/2;
        while(mid>=0){
            if(mid==0){
                if(prev){
                    prev->next=curr->next;
                    return head;
                }
                else return prev;
            }
            else{
                mid--;
                prev=curr;
                curr=curr->next;
            }
        }
        return prev;
    }
};