class Solution {
public:
    void test(vector<int>& nums,int ind,int sum,int& target,int& ans){
        if(ind==nums.size()){
            if(sum==target)
            ans++;
            return;
        }
        test(nums,ind+1,sum-nums[ind],target,ans);
        test(nums,ind+1,sum+nums[ind],target,ans);
        return;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int ans=0;
        test(nums,0,0,target,ans);
        return ans;
    }
};