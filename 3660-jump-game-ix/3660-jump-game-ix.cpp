class Solution {
public:
    vector<int> maxValue(vector<int>& nums) {
        vector<int> pre(nums.size(),0),suf(nums.size(),0),ans(nums.size(),0);
        pre[0]=nums[0];
        for(int i=1;i<nums.size();i++)
        pre[i]=max(pre[i-1],nums[i]);
        suf[nums.size()-1]=nums[nums.size()-1];
        for(int i=nums.size()-2;i>=0;i--)
        suf[i]=min(suf[i+1],nums[i]);
        ans[nums.size()-1]=pre[nums.size()-1];
        for(int i=nums.size()-2;i>=0;i--){
            if(pre[i]>suf[i+1]){
                ans[i]=ans[i+1];
            }
            else{
                ans[i]=pre[i];
            }
        }
        return ans;
    }
};