/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(!head)
        return head;
        int i=1;
        ListNode* odd=nullptr;
        ListNode* even=nullptr;
        ListNode* o=nullptr;
        ListNode* tail=nullptr;
        ListNode* e=nullptr;
        while(head){
            if(i%2){
                if(!o){
                    o=head;
                    odd=head;
                }
                else{
                    o->next=head;
                    o=o->next;
                }
            }
            else{
                if(!e){
                    e=head;
                    even=head;
                }                
                else{
                    e->next=head;
                    e=e->next;
                }
            }
            i++;
            head=head->next;
        }
        if(e)
        e->next=nullptr;
        if(o)
        o->next=even;
        return odd;
    }
};