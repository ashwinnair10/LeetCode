class Solution {
public:
    int findMaxK(vector<int>& nums) {
        unordered_set<int> set;
        int max=0;
        for(auto num:nums){
            if(set.find(-num)!=set.end()&&abs(num)>max)
            max=abs(num);
            set.insert(num);
        }
        return max?max:-1;
    }
};