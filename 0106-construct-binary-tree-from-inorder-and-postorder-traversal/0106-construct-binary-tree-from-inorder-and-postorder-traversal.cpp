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
    TreeNode* test(vector<int>& postorder,int& post,int ins,int ine,unordered_map<int,int>& idx){
        if(ins>ine)
        return nullptr;
        int val=postorder[post];
        TreeNode* root=new TreeNode(val);
        post--;
        root->right=test(postorder,post,idx[val]+1,ine,idx);
        root->left=test(postorder,post,ins,idx[val]-1,idx);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n=inorder.size();
        unordered_map<int,int> inorder_index;
        for(int i=0;i<n;i++){
            inorder_index[inorder[i]]=i;
        }
        int post=n-1;
        return test(postorder,post,0,n-1,inorder_index);
    }
};