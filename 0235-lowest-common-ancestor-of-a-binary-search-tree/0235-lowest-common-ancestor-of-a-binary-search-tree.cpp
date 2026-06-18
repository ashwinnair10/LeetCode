/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int s=min(p->val,q->val);
        int l=max(p->val,q->val);
        while(root!=nullptr){
            if(root->val>l){
                root=root->left;
            }
            else if(root->val<s){
                root=root->right;
            }
            else
            return root;
        }
        return nullptr;
    }
};