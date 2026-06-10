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
    int m=0;
    int count(TreeNode* root,int dir,int l){
        if(!root)
        return 0;
        m=max(m,l);
        if(dir)
        return max(count(root->left,0,0),1+count(root->right,0,l+1));
        return max(count(root->right,1,0),1+count(root->left,1,l+1));
    }
    int longestZigZag(TreeNode* root) {
        count(root,0,0);
        count(root,1,0);
        return m;
    }
};