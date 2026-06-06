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
    TreeNode* test(vector<int>& preorder,int& pre,int ins,int ine,unordered_map<int,int>& idx){
        if(ins>ine)
        return nullptr;
        int val=preorder[pre];
        TreeNode* root=new TreeNode(val);
        pre++;
        root->left=test(preorder,pre,ins,idx[val]-1,idx);
        root->right=test(preorder,pre,idx[val]+1,ine,idx);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n=inorder.size();
        unordered_map<int,int> inorder_index;
        for(int i=0;i<n;i++){
            inorder_index[inorder[i]]=i;
        }
        int pre=0;
        return test(preorder,pre,0,inorder.size()-1,inorder_index);
    }
};