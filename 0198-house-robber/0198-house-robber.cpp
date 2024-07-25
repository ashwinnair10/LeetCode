class Solution {
public:
    int test(vector<int>& a,vector<int>& dp,int ind,int n){
        if(ind>=n)
        return 0;
        if(dp[ind]!=INT_MIN)
        return dp[ind];
        dp[ind]=max(test(a,dp,ind+1,n),a[ind]+test(a,dp,ind+2,n));
        return dp[ind];
    }
    int rob(vector<int>& a) {
        int n=a.size();
        vector<int> dp(n,INT_MIN);
        return test(a,dp,0,n);
    }
};