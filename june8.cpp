class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        int sum=0;
        unordered_map<int,int> map;
        for(int i=0;i<n;i++){
            sum=(sum+nums[i])%k;
            if((!sum&&i)||map.find(sum)!=map.end()&&i-map[sum]>1){
                return true;
            }
            else
            map.insert(make_pair(sum,i));
        }
        return false;
    }
};