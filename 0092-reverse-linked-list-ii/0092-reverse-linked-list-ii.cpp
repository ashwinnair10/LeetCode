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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        int t=1;
        ListNode* startparent=nullptr;
        ListNode* start;
        ListNode* end;
        ListNode* endchild=nullptr;
        ListNode* root=head;
        ListNode* parent=nullptr;
        while(root){
            if(t==left){
                startparent=parent;
                start=root;
            }
            if(t==right){
                end=root;
                endchild=root->next;
            }
            parent=root;
            root=root->next;
            t++;
        }
        ListNode* prev=endchild;
        ListNode* curr=start;
        ListNode* next;
        while(curr!=end){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
        if(startparent)
        startparent->next=prev;
        return startparent?head:prev;
    }
};