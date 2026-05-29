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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* root=new ListNode(-1);
        root->next=head;
        ListNode* nh=root;
        while(root){
            if(root->next&&root->next->val==val){
                root->next=root->next->next;
            }
            else
            root=root->next;
        }
        return nh->next;
    }
};