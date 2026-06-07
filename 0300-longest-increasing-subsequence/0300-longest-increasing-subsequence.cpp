class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> tails;
        for(auto i:nums){
            auto it=lower_bound(tails.begin(),tails.end(),i);
            if(it==tails.end()){
                tails.push_back(i);
            }
            else{
                *it=i;
            }
        }
        return tails.size();
    }
};