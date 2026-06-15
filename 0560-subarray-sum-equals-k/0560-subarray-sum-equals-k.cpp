class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> map;
        int ans=0,s=0;
        map[0]=1;
        for(int i=0;i<nums.size();i++){
            s+=nums[i];
            if(map[s-k]!=0){
                ans+=map[s-k];
            }
            map[s]++;
            cout<<"s : "<<s<<"\n";
        }
        return ans;
    }
};