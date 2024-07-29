class Solution {
public:
    void backtrack(vector<vector<int>>& ans,vector<int>& v,vector<int>& a,int ind,int count,int k){
        v.push_back(a[ind]);
        count++;
        if(count==k){
            ans.push_back(v);
            v.pop_back();
            count--;
            return;
        }
        for(int i=ind+1;i<a.size();i++){
            backtrack(ans,v,a,i,count,k);
        }
        v.pop_back();
        count--;
        return;
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int> a;
        vector<vector<int>> ans;
        vector<int> v;
        for(int i=0;i<n;i++)
        a.push_back(i+1);
        for(int i=0;i<n;i++){
            backtrack(ans,v,a,i,0,k);
        }
        return ans;
    }
};