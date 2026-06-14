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
    void reorderList(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast!=nullptr&&fast->next!=nullptr){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* mh=slow->next;
        slow->next=nullptr;
        ListNode* prev=nullptr;
        ListNode* curr=mh;
        ListNode* next;
        while(curr!=nullptr){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        ListNode* start=head;
        while(prev!=nullptr){
            ListNode* t1=start->next;
            ListNode* t2=prev->next;
            start->next=prev;
            prev->next=t1;
            start=t1;
            prev=t2;
        }
        return;
    }
};