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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if(!root)
        return {};
        vector<vector<int>> levels;
        queue<pair<TreeNode*,int>> q;
        q.push({root,0});
        while(!q.empty()){
            TreeNode* curr=q.front().first;
            cout<<curr->val<<"\n";
            int l=q.front().second;
            q.pop();
            if(l==levels.size())
            levels.push_back({});
            levels[l].push_back(curr->val);
            if(curr->left!=nullptr)
            q.push({curr->left,l+1});
            if(curr->right!=nullptr)
            q.push({curr->right,l+1});
        }
        reverse(levels.begin(),levels.end());
        return levels;
    }
};