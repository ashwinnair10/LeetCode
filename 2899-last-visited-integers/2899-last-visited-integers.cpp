class Solution {
public:
    vector<int> lastVisitedIntegers(vector<int>& nums) {
        vector<int> ans,seen;
        int k=0;
        for(auto i:nums){
            if(i==-1){
                if(k>=seen.size()){
                    ans.push_back(-1);
                }
                else{
                    ans.push_back(seen[seen.size()-1-k]);
                }
                k++;
            }
            else{
                k=0;
                seen.push_back(i);
            }
        }
        return ans;
    }
};