class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<int> sum;
        for(int i=0;i<n;i++){
            int s=0;
            for(int j=i;j<n;j++){
                s+=nums[j];
                sum.push_back(s);
            }
        }
        sort(sum.begin(),sum.end());
        int ans=0;
        for(int i=left-1;i<=right-1;i++)
        ans=(ans+sum[i]%1000000007)%1000000007;
        return ans;
    }
};