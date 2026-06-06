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
    TreeNode* test(vector<int>& preorder,vector<int>& inorder,int ind){
        if(inorder.size()==0)
        return nullptr;
        if(inorder.size()==1){
            return new TreeNode(inorder[0]);
        }
        TreeNode* root=new TreeNode(preorder[ind]);
        vector<int> left,right;
        bool l=true;
        for(int i=0;i<inorder.size();i++){
            if(inorder[i]!=preorder[ind]){
                if(l)
                left.push_back(inorder[i]);
                else
                right.push_back(inorder[i]);
            }
            else l=false;
        }
        root->left=test(preorder,left,ind+1);
        root->right=test(preorder,right,ind+1+left.size());
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return test(preorder,inorder,0);
    }
};