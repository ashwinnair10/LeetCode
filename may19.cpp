class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edge) {
        long long sum=0;
        int c=0,p=INT_MAX,q=INT_MIN;
        for(auto num:nums){
            int m=num^k;
            sum+=num;
            int del=m-num;
            if(del>0){
                p=min(p,del);
                sum+=del;
                c++;
            }
            else{
                q=max(q,del);
            }
        }
        if(c%2)
        return max(sum-p,sum+q);
        return sum;
    }
};