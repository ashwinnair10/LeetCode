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
    void test(TreeNode* root,string s,vector<string>& ans){
        if(root==nullptr)
        return;
        if(root->left==nullptr&&root->right==nullptr){
            ans.push_back(s+to_string(root->val));
        }
        else
        s+=to_string(root->val)+"->";
        test(root->left,s,ans);
        test(root->right,s,ans);
        return;
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        string s="";
        vector<string> ans;
        test(root,s,ans);
        return ans;
    }
};