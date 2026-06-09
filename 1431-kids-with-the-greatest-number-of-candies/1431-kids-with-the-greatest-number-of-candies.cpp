class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int e) {
        int m=0;
        for(auto i:candies){
            m=max(m,i);
        }
        vector<bool> ans;
        for(auto i:candies){
            ans.push_back((i+e)>=m);
        }
        return ans;
    }
};