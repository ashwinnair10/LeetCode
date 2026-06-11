class Solution {
public:
    void dfs(vector<vector<int>>& ans,int ind,int sum,int k,int n,vector<int>& v){
        if(v.size()==k){
            if(sum==n)
            ans.push_back(v);
            return;
        }
        if(sum>=n)
        return;
        for(int i=ind+1;i<10;i++){
            v.push_back(i);
            dfs(ans,i,sum+i,k,n,v);
            v.pop_back();
        }
        return;
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> v;
        for(int i=1;i<10;i++){
            v.push_back(i);
            dfs(ans,i,i,k,n,v);
            v.pop_back();
        }
        return ans;
    }
};