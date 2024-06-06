class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int> prefix(n,1);
        vector<int> suffix(n,1);
        for(int i=1;i<n;i++){
            prefix[i]=prefix[i-1]*nums[i-1];
            suffix[n-i-1]=suffix[n-i]*nums[n-i];
        }    
        vector<int> vec;
        for(int i=0;i<nums.size();i++){
            vec.push_back(prefix[i]*suffix[i]);
        }
        return vec;
    }
};