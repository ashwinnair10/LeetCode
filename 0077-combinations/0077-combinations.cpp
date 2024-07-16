class Solution {
public:
    void test(vector<vector<int>>& ans,vector<int> curr,vector<int>& a,int ind,int n,int c,int k){
        if(c==k){
            curr.push_back(a[ind]);
            ans.push_back(curr);
            return;
        }
        if(ind>=n)
        return;
        curr.push_back(a[ind]);
        for(int i=ind+1;i<n;i++){
            test(ans,curr,a,i,n,c+1,k);
        }
        curr.pop_back();
        return;
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> curr;
        vector<int> a;
        for(int i=0;i<n;i++)
        a.push_back(i+1);
        for(int i=0;i<n;i++){
            test(ans,curr,a,i,n,1,k);
        }
        return ans;
    }
};