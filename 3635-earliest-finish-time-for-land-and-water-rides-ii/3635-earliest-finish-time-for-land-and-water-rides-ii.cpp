class Solution {
public:
    int test(vector<int>& s1,vector<int>& d1,vector<int>& s2,vector<int>& d2){
        int e=INT_MAX;
        for(int i=0;i<s1.size();i++){
            e=min(e,s1[i]+d1[i]);
        }
        int ans=INT_MAX;
        for(int i=0;i<s2.size();i++){
            ans=min(ans,max(s2[i],e)+d2[i]);
        }
        return ans;
    }
    int earliestFinishTime(vector<int>& lst, vector<int>& ld, vector<int>& wst, vector<int>& wd) {
        return min(test(lst,ld,wst,wd),test(wst,wd,lst,ld));
    }
};