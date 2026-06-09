class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int c=0;
        for(auto i:nums){
            if(!i)
            c++;
        }
        int l=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]){
                nums[l++]=nums[i];
            }
        }
        while(l<nums.size()){
            nums[l++]=0;
        }
        return;
    }
};