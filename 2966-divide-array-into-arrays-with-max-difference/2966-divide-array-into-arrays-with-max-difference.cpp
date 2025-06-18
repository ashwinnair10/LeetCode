class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        vector<vector<int>> ans(nums.size()/3);
        sort(nums.begin(),nums.end());
        int j=0,ind=0;
        for(int i=0;i<nums.size();i++){
            if(j==0){
                ans[ind].push_back(nums[i]);
            }
            else if(j==1){
                if(nums[i]-ans[ind][0]>k){
                    return {};
                }
                ans[ind].push_back(nums[i]);
            }
            else{
                if(nums[i]-ans[ind][0]>k||nums[i]-ans[ind][1]>k){
                    return {};
                }
                ans[ind].push_back(nums[i]);
                ind++;
            }
            j=(j+1)%3;
        }
        return ans;
    }
};