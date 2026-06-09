class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int l=0,r=nums.size()-1,c=0;
        while(l<r){
            if(nums[l]+nums[r]==k){
                c++;
                l++;
                r--;
            }
            else if(nums[l]+nums[r]>k)
            r--;
            else
            l++;
        }
        return c;
    }
};