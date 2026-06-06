class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int sum=nums[0];
        int l=0,r=0;
        int len=INT_MAX;
        while(l<=r&&r<nums.size()){
            if(sum>=target){
                len=min(len,r-l+1);
                sum-=nums[l];
                l++;
            }
            if(sum<target){
                r++;
                if(r>=nums.size())break;
                sum+=nums[r];
            }
        }
        return len==INT_MAX?0:len;
    }
};