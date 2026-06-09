class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        long long ma=INT_MIN,mi=INT_MAX;
        for(auto i:nums){
            ma=max(ma,(long long)i);
            mi=min(mi,(long long)i);
        }
        return (long long)(k)*(ma-mi);
    }
};