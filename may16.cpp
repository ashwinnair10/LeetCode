class Solution {
public:
    bool evaluateTree(TreeNode* root) {
        if(root->val==2)
        return evaluateTree(root->left)|evaluateTree(root->right);
        if(root->val==3)
        return evaluateTree(root->left)&evaluateTree(root->right);
        else return root->val;
    }
};