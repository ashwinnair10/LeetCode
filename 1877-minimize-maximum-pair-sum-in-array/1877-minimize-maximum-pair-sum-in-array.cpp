class Solution {
public:
    int minPairSum(vector<int>& nums) {
        int ans=INT_MIN;
        sort(nums.begin(),nums.end());
        int l=0,r=nums.size()-1;
        while(l<r){
            ans=max(ans,nums[l]+nums[r]);
            l++;
            r--;
        }
        return ans;
    }
};