class Solution {
public:
    vector<vector<int>> res;
    vector<string> direction;
    void findpath(TreeNode* root,vector<int>& path,string& dir,int& target){
        if(root==nullptr)
        return;
        if(root->val==target){
            path.push_back(target);
            res.push_back(path);
            direction.push_back(dir);
            return;
        }
        path.push_back(root->val);
        dir+='L';
        findpath(root->left,path,dir,target);
        dir.pop_back();
        path.pop_back();
        dir+='R';
        path.push_back(root->val);
        findpath(root->right,path,dir,target);
        dir.pop_back();
        path.pop_back();
        return;
    }
    string getDirections(TreeNode* root, int s, int t) {
        vector<int> sp,tp;
        string sd,td;
        findpath(root,sp,sd,s);
        findpath(root,tp,td,t);
        int l,r;
        l=0,r=0;
        while(l<direction[0].length()&&r<direction[1].length()){
            if(direction[0][l]==direction[1][r]){
                l++;
                r++;
            }
            else break;
        }
        string ans;
        for(int j=l;j<direction[0].size();j++)
        ans+='U';
        for(int j=r;j<direction[1].size();j++)
        ans+=direction[1][j];
        return ans;
    }
};