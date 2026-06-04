class Solution {
public:
    int totalWaviness(int num1, int num2) {
        if(num2/100==0)
        return 0;
        vector<int> dp(100001,0);
        for(int i=100;i<=num2;i++){
            dp[i]=dp[i/10];
            int l=(i/100)%10,m=(i/10)%10,r=i%10;
            if(m>l&&m>r)
            dp[i]++;
            if(m<l&&m<r)
            dp[i]++;
        }
        int ans=0;
        for(int i=num1;i<=num2;i++){
            ans+=dp[i];
        }
        return ans;
    }
};