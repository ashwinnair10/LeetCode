class Solution {
public:
    int specialArray(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int j=0;
        for(int i=0;i<=nums[n-1]&&j<=n-1;i++){
            if(i<nums[j]&&i==n-j){
                return i;
            }
            else if(i==nums[j]){
                if(i==n-j)
                return i;
                else 
                while(nums[j]==i&&j<n-1)
                j++;
                if(j>=n)
                return -1;
            }
            else if(i>nums[j]){
                j++;
            }
        }
        return -1;
    }
};