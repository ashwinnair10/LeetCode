class Solution {
public:
    int m=INT_MAX;
    int test(vector<int>& a,vector<int>& dp,int ind,int n){
        if(ind>=n-1){
            return 0;
        }
        else if(dp[ind]!=99999){
            return dp[ind];
        }
        for(int i=1;i<=a[ind];i++){
            dp[ind]=min(dp[ind],1+test(a,dp,ind+i,n));
        }
        return dp[ind];
    }
    int jump(vector<int>& a) {
        int n=a.size();
        vector<int> dp(n,99999);
        return test(a,dp,0,n);
    }
};