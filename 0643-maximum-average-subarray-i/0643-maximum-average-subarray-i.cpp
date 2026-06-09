class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double s=0;
        for(int i=0;i<k;i++){
            s+=nums[i];
        }
        double m=s;
        for(int i=1;i<=nums.size()-k;i++){
            s=s+nums[i+k-1]-nums[i-1];
            m=max(m,s);
        }
        return m/k;
    }
};