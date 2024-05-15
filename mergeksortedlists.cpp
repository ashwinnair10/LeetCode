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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k=lists.size();
        if(!k)
        return nullptr;
        ListNode* head=nullptr;
        ListNode* tail=nullptr;
        while(1){
            ListNode* min=lists[0];
            int ind=0;
            for(int i=1;i<k;i++){
                if(lists[i]==nullptr)
                continue;
                else if(min==nullptr&&lists[i]!=nullptr){
                    min=lists[i];
                    ind=i;
                }
                else if(lists[i]->val<min->val){
                    min=lists[i];
                    ind=i;
                }
            }
            if(min==nullptr)
            break;
            if(head==nullptr){
                head=new ListNode(min->val);
                tail=head;
            }
            else{
                tail->next=new ListNode(min->val);
                tail=tail->next;
            }
            lists[ind]=lists[ind]->next;
        }
        return head;
    }
};