class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int sum=nums[0]+nums[1]+nums[2];
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            int x=nums[i];
            int l=i+1,r=nums.size()-1;
            while(l<r){
                if(abs(target-(x+nums[l]+nums[r]))<abs(target-sum))
                sum=x+nums[l]+nums[r];
                if(x+nums[l]+nums[r]==target)
                break;
                else if(x+nums[l]+nums[r]<target)
                l++;
                else
                r--;
            }
        }
        return sum;
    }
};