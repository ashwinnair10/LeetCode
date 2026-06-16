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
        ListNode* ans=nullptr;
        ListNode* res=nullptr;
        vector<ListNode*> nodes;
        for(int i=0;i<lists.size();i++){
            nodes.push_back(lists[i]);
        }
        bool valid=false;
        for(auto i:nodes){
            valid=valid || (i!=nullptr);
            if(valid)
            break;
        }
        while(valid){
            int min=-1;
            for(int i=0;i<lists.size();i++){
                if(min==-1&&nodes[i]!=nullptr)
                min=i;
                if(nodes[i]!=nullptr&&nodes[i]->val<nodes[min]->val){
                    min=i;
                }
            }
            if(min==-1)
            break;
            if(res==nullptr){
                res=nodes[min];
                ans=res;
            }
            else{
                res->next=nodes[min];
                res=res->next;
            }
            nodes[min]=nodes[min]->next;
            for(auto i:nodes){
                valid=valid || (i!=nullptr);
                if(valid)
                break;
            }
        }
        return ans;
    }
};