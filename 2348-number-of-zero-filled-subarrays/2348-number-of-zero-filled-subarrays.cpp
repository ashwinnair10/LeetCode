class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long ans=0;
        int c=0;
        for(auto i:nums){
            if(i){
                ans+=(c*(c+1))/2;
                c=0;
            }
            else{
                c++;
            }
        }
        ans+=(c*(c+1))/2;
        return ans;
    }
};