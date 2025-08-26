class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        sort(intervals.begin(),intervals.end());
        int curr=intervals[0][0],last=intervals[0][1];
        for(auto i:intervals){
            if(i[0]<=last){
                last=last>i[1]?last:i[1];
            }
            else{
                ans.push_back({curr,last});
                curr=i[0];
                last=i[1];
            }
        }
        ans.push_back({curr,last});
        return ans;
    }
};