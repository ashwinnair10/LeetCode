class Solution {
public:
    long long test(int ind,int n,int type,vector<vector<long long>>& dp){
        long long l,r;
        if(ind>n)
            return 1;
        if(dp[ind][type]!=0){
            return dp[ind][type];
        }
        if(ind==1){
            l=6;
            r=6;
        }
        else{
            if(type==0){
                l=2;
                r=2;
            }
            else{
                l=3;
                r=2;
            }
        }
        return dp[ind][type]=(l*test(ind+1,n,1,dp)+r*test(ind+1,n,0,dp))%1000000007;
    }
    int numOfWays(int n) {
        vector<vector<long long>> dp(n+1,vector<long long>(2));
        int ans=(int)(test(1,n,0,dp));
        return ans;
    }
};