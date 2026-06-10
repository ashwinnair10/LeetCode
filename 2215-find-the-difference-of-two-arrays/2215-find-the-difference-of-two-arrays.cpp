class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> ans(2);
        unordered_map<int,int> a,b;
        for(auto i:nums1)
        a[i]++;
        for(auto i:nums2)
        b[i]++;
        for(auto i:nums1){
            if(!b[i])
            ans[0].push_back(i);
            b[i]=1;
        }
        for(auto i:nums2){
            if(!a[i])
            ans[1].push_back(i);
            a[i]=1;
        }
        return ans;
    }
};