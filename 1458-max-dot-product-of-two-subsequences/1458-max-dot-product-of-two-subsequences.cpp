class Solution {
public:
    int test(int i,int j,vector<vector<int>>& dp,vector<int>& a,vector<int>& b){
        if(i==a.size()||j==b.size())
        return -1e6;
        if(dp[i][j]!=-1e6)
        return dp[i][j];
        int p=a[i]*b[j]+test(i+1,j+1,dp,a,b);
        int q=a[i]*b[j];
        int r=test(i+1,j,dp,a,b);
        int s=test(i,j+1,dp,a,b);
        return dp[i][j]=max(max(p,q),max(r,s));
    }
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> dp(nums1.size(),vector<int>(nums2.size(),-1e6));
        return test(0,0,dp,nums1,nums2);
    }
};