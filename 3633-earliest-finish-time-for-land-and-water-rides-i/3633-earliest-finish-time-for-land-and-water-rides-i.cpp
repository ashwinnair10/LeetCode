class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int ans=INT_MAX;
        for(int i=0;i<landStartTime.size();i++){
            int lstart=landStartTime[i];
            int lduration=landDuration[i];
            for(int j=0;j<waterStartTime.size();j++){
                int wstart=waterStartTime[j];
                int wduration=waterDuration[j];
                if(wstart<=lstart+lduration){
                    ans=min(ans,lstart+lduration+wduration);
                }
                else{
                    ans=min(ans,wstart+wduration);
                }
            }
        }
        for(int i=0;i<waterStartTime.size();i++){
            int wstart=waterStartTime[i];
            int wduration=waterDuration[i];
            for(int j=0;j<landStartTime.size();j++){
                int lstart=landStartTime[j];
                int lduration=landDuration[j];
                if(lstart<=wstart+wduration){
                    ans=min(ans,wstart+wduration+lduration);
                }
                else{
                    ans=min(ans,lstart+lduration);
                }
            }
        }
        return ans;
    }
};