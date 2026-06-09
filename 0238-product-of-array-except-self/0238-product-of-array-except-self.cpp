class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> p,s;
        int n=nums.size();
        int a=1,b=1;
        for(int i=0;i<n;i++){
            p.push_back(a);
            a*=nums[i];
            s.push_back(b);
            b*=nums[n-1-i];
        }
        for(int i=0;i<n;i++){
            p[i]=p[i]*s[n-1-i];
        }
        return p;
    }
};