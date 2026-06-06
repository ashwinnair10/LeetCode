class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int,int>> vec;
        for(int i=0;i<nums.size();i++){
            vec.push_back({nums[i],i});
        }
        sort(vec.begin(),vec.end());
        int l=0,r=vec.size()-1;
        while(l<r){
            if(vec[l].first+vec[r].first==target)
            return {vec[l].second,vec[r].second};
            else if(vec[l].first+vec[r].first<target)
            l++;
            else
            r--;
        }
        return {};
    }
};