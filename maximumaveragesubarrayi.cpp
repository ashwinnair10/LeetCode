class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n=nums.size();
        int sum=0,maxsum;
        for(int i=0;i<k;i++)
        sum+=nums[i];
        maxsum=sum;
        for(int i=1;i<n-k+1;i++){
            sum=sum-nums[i-1]+nums[i+k-1];
            maxsum=max(maxsum,sum);
        }
        return maxsum/(double)k;
    }
};