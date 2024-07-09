class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& a) {
        double ans=0;
        double last=a[0][0];
        for(int i=0;i<a.size();i++){
            last=last>a[i][0]?last+a[i][1]:a[i][0]+a[i][1];
            ans+=last-a[i][0];
        }
        return ans/a.size();
    }
};