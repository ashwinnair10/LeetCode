class Solution {
public:
    vector<int> ans;
    void pos(TreeNode* root){
        if(root!=nullptr){
            pos(root->left);
            pos(root->right);
            ans.push_back(root->val);
        }
    }
    vector<int> postorderTraversal(TreeNode* root) {
        pos(root);
        return ans;
    }
};