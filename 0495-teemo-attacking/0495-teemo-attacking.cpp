class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int ans=0;
        int start=timeSeries[0];
        for(int i=1;i<timeSeries.size();i++){
            if(timeSeries[i]>start+duration-1){
                ans+=duration;
                start=timeSeries[i];
            }
            else{
                ans+=timeSeries[i]-start;
                start=timeSeries[i];
            }
        }
        ans+=duration;
        return ans;
    }
};