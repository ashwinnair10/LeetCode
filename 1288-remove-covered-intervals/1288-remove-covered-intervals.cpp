class Solution {
public:
    static bool cmp(const vector<int>& a,const vector<int>& b){
        return a[0]==b[0]?a[1]>b[1]:a[0]<b[0];
    }
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),cmp);
        int ans=intervals.size();
        int s=intervals[0][0],e=intervals[0][1];
        for(int i=1;i<intervals.size();i++){
            if(intervals[i][0]>=s&&intervals[i][1]<=e){
                ans--;
            }
            else{
                s=intervals[i][0];
                e=intervals[i][1];
            }
        }
        return ans;
    }
};