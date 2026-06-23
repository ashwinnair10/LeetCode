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
    void test(TreeNode* root,int& l,int& r,int off,int& md,int d){
        if(root==nullptr){
            return;
        }
        l=min(l,off);
        r=max(r,off);
        md=max(md,d);
        test(root->left,l,r,off-1,md,d+1);
        test(root->right,l,r,off+1,md,d+1);
        return;
    }
    void test1(vector<vector<vector<int>>>& ans,TreeNode* root,int& l,int off,int d){
        if(root==nullptr){
            return;
        }
        ans[d][abs(l)+off].push_back(root->val);
        test1(ans,root->left,l,off-1,d+1);
        test1(ans,root->right,l,off+1,d+1);
        return;
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        int l=0,r=0,d=0;
        test(root,l,r,0,d,0);
        vector<vector<vector<int>>> ans(d+1,vector<vector<int>>(r-l+1));
        vector<vector<int>> res(r-l+1);
        test1(ans,root,l,0,0);
        for(int i=0;i<ans.size();i++){
            for(int j=0;j<ans[i].size();j++){
                sort(ans[i][j].begin(),ans[i][j].end());
                for(int k=0;k<ans[i][j].size();k++){
                    res[j].push_back(ans[i][j][k]);
                }
            }
        }
        return res;
    }
};