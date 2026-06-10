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
    int pairSum(ListNode* head) {
        int n=0;
        int ans=0;
        unordered_map<int,int> map;
        ListNode* root=head;
        while(root){
            n++;
            root=root->next;
        }
        int c=0;
        root=head;
        while(root){
            map[c]=root->val;
            ans=max(ans,root->val+map[n-1-c]);
            c++;
            root=root->next;
        }
        return ans;
    }
};