class Solution {
public:
    static int distributeCoins(TreeNode* root,TreeNode* parent=NULL) {
        if(root==nullptr)
        return 0;
        int moves=distributeCoins(root->left,root)+distributeCoins(root->right,root);
        if(parent!=nullptr)
        parent->val+=root->val-1;
        moves+=abs(root->val-1);
        return moves;
    }
};