class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        int j=0,ind=0;
        for(int i=0;i<nums.size();i+=3){
            if(nums[i+2]-nums[i]>k||nums[i+1]-nums[i]>k){
                return {};
            }
            ans.push_back({nums[i],nums[i+1],nums[i+2]});
        }
        return ans;
    }
};