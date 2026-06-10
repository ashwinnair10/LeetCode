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
    void traverse(TreeNode* root,int l,vector<vector<int>>& level){
        if(!root)
        return;
        if(l>=level.size()){
            level.push_back({});
        }
        level[l].push_back(root->val);
        traverse(root->left,l+1,level);
        traverse(root->right,l+1,level);
        return;
    }
    int maxLevelSum(TreeNode* root) {
        vector<vector<int>> level;
        traverse(root,0,level);
        int m=INT_MIN,ans=0;
        for(int i=0;i<level.size();i++){
            int s=0;
            for(auto j:level[i]){
                cout<<j<<" ";
                s+=j;
            }
            cout<<"\n";
            if(m<s){
                ans=i;
                m=s;
            }
        }
        return ans+1;
    }
};