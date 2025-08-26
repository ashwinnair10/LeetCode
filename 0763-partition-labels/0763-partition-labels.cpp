class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> first(26,-1),last(26,-1);
        for(int i=0;i<s.length();i++){
            if(first[s[i]-97]==-1){
                first[s[i]-97]=i;
            }
            last[s[i]-97]=i;
        }
        vector<vector<int>> intervals;
        for(int i=0;i<26;i++){
            if(first[i]!=-1&&last[i]!=-1){
                intervals.push_back({first[i],last[i]});
            }
        }
        vector<int> ans;
        sort(intervals.begin(),intervals.end());
        int curr=intervals[0][0],l=intervals[0][1];
        for(auto i:intervals){
            if(i[0]<=l){
                l=l>i[1]?l:i[1];
            }
            else{
                ans.push_back(l-curr+1);
                curr=i[0];
                l=i[1];
            }
        }
        ans.push_back(l-curr+1);
        return ans;
    }
};