class Solution {
public:
    vector<vector<int>> res;
    void test(TreeNode* root,int sum,int t,vector<int>& v){
        if(root!=nullptr){
            sum+=root->val;
            v.push_back(root->val);
            if(sum==t&&root->left==nullptr&&root->right==nullptr)
            res.push_back(v);
            test(root->left,sum,t,v);
            test(root->right,sum,t,v);
            v.pop_back();
        }
        return;
    }
    vector<vector<int>> pathSum(TreeNode* root, int t) {
        vector<int> v;
        test(root,0,t,v);
        return res;
    }
};