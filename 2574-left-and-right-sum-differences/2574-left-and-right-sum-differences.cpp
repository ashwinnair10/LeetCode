class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int sum=0;
        for(auto i:nums){
            sum+=i;
        }
        vector<int> ans;
        int left=0,right=sum;
        for(int i=0;i<nums.size();i++){
            right-=nums[i];
            ans.push_back(abs(right-left));
            left+=nums[i];
        }
        return ans;
    }
};