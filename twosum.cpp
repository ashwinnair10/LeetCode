#include <vector>
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result={-1,-1};
        unordered_map<int,int> hash;
        for(int i=0;i<nums.size();i++){
            if(hash.find(target-nums[i])!=hash.end()){
                result[0]=hash[target-nums[i]];
                result[1]=i;
                return result;
            }
            hash[nums[i]]=i;
        }
        return result;
    }
};