/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void traverse(TreeNode* root,int& ans,int curr_min){
        if(!root)
        return;
        if(root->val>=curr_min){
            ans++;
        }
        curr_min=max(curr_min,root->val);
        traverse(root->left,ans,curr_min);
        traverse(root->right,ans,curr_min);
        return;
    }
    int goodNodes(TreeNode* root) {
        if(!root)
        return 0;
        int ans=0;
        traverse(root,ans,root->val);
        return ans;
    }
};