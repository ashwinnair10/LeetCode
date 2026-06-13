class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.push_back(newInterval);
        sort(intervals.begin(),intervals.end());
        for(auto i:intervals){
            cout<<i[0]<<" "<<i[1]<<"\n";
        }
        vector<vector<int>> ans;
        int start=intervals[0][0],end=intervals[0][1];
        for(int i=1;i<intervals.size();i++){
            if(intervals[i][0]>end){
                ans.push_back({start,end});
                start=intervals[i][0];
                end=intervals[i][1];
            }
            else{
                end=max(end,intervals[i][1]);
            }
        }
        ans.push_back({start,end});
        return ans;
    }
};