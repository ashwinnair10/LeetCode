class Solution {
public:
    vector<int> a;
    void inorder(TreeNode* root) {
        if (root != nullptr) {
            inorder(root->left);
            a.push_back(root->val);
            inorder(root->right);
        }
    }
    TreeNode* bst(int l,int r){
        if(l<=r){
            int m=l+(r-l)/2;
            TreeNode* root=new TreeNode(a[m]);
            root->left=bst(l,m-1);
            root->right=bst(m+1,r);
            return root;
        }
        return nullptr;
    }
    TreeNode* balanceBST(TreeNode* root) {
        inorder(root);
        return bst(0,a.size()-1);
    }
};