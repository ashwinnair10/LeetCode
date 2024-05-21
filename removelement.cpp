class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            while(i<nums.size()&&nums[i]==val){
                nums.erase(nums.begin()+i);
            }
        }
        return nums.size();
    }
};