class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> index;
        int i=0;
        while(head!=nullptr&&head->next!=nullptr&&head->next->next!=nullptr){
            if(head->val>head->next->val&&head->next->val<head->next->next->val)
            index.push_back(i+1);
            else if(head->val<head->next->val&&head->next->val>head->next->next->val)
            index.push_back(i+1);
            i++;
            head=head->next;
        }
        if(!index.size())
        return {-1,-1};
        int mid=INT_MAX;
        for(int i=0;i<index.size()-1;i++)
        mid=min(mid,index[i+1]-index[i]);
        if(mid==INT_MAX)
        return {-1,-1};
        return {mid,index[index.size()-1]-index[0]};
    }
};