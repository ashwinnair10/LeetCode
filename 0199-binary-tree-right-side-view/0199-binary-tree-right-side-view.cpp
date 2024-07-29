class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        queue<TreeNode* > q;
        vector<int> vec;
        TreeNode* x=new TreeNode(INT_MAX);
        if(root==nullptr)
        return vec;
        q.push(root);
        q.push(x);
        while(!q.empty()){
            TreeNode* curr=q.front();
            q.pop();
            TreeNode* check=q.front();
            if(check==x){
                vec.push_back(curr->val);
                q.pop();
            }
            if(curr->left!=nullptr)
            q.push(curr->left);
            if(curr->right!=nullptr)
            q.push(curr->right);
            if(check==x)
            q.push(x);
        }
        return vec;
    }
};