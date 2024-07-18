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
    vector<vector<int>> res;
    void test(TreeNode* root,int sum,int t,vector<int> v){
        if(root!=nullptr){
            sum+=root->val;
            v.push_back(root->val);
            if(sum==t&&root->left==nullptr&&root->right==nullptr)
            res.push_back(v);
            test(root->left,sum,t,v);
            test(root->right,sum,t,v);
        }
        return;
    }
    vector<vector<int>> pathSum(TreeNode* root, int t) {
        test(root,0,t,{});
        return res;
    }
};