class Solution {
public:
    int minPairSum(vector<int>& nums) {
        int ans=INT_MIN;
        sort(nums.begin(),nums.end());
        vector<pair<int,int>> v;
        int l=0,r=nums.size()-1;
        while(l<r){
            // while(l+1<=r&&nums[l]==nums[l+1]){
            //     ans=max(ans,nums[l]*2);
            //     cout<<"ans : "<<ans<<"\n";
            //     l+=2;
            // }
            // while(r-1>=l&&nums[r]==nums[r-1]){
            //     ans=max(ans,nums[r]*2);
            //     cout<<"ans : "<<ans<<"\n";
            //     r-=2;
            // }
            // if(l<r)
            ans=max(ans,nums[l]+nums[r]);
            cout<<"ans : "<<ans<<"\n";
            l++;
            r--;
        }
        return ans;
    }
};