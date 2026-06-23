class Solution {
public:
    int thirdMax(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int a=nums[nums.size()-1],c=1;
        int b=a;
        for(int i=nums.size()-2;i>=0;i--){
            if(a!=nums[i]){
                c++;
                a=nums[i];
                if(c==3)
                return a;
            }
            b=max(b,nums[i]);
        }
        return b;
    }
};