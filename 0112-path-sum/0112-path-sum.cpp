class Solution {
public:
    bool f=false;
    void test(TreeNode* root,int sum,int t){
        if(root!=nullptr){
            sum+=root->val;
            if(sum==t&&root->left==nullptr&&root->right==nullptr)
            f=true;
            test(root->left,sum,t);
            test(root->right,sum,t);
        }
        return;
    }
    bool hasPathSum(TreeNode* root, int t) {
        test(root,0,t);
        return f;
    }
};