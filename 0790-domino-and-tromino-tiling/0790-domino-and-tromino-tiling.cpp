class Solution {
public:
    int numTilings(int n) {
        int k=1000000007;
        if(n<=2)
        return n;
        if(n==3)
        return 5;
        vector<int> dp(n,0);
        dp[0]=1;
        dp[1]=2;
        dp[2]=5;
        for(int i=3;i<n;i++){
            dp[i]=((dp[i-1]%k)*2)%k + dp[i-3]%k;
            dp[i]%=k;
        }
        return dp[n-1];
    }
};