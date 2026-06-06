class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0||nums.size()==1)
        return nums.size();
        unordered_map<int,bool> map;
        for(auto i:nums){
            map[i]=true;
        }
        for(auto i:nums){
            if(!map[i-1]&&!map[i+1])
            map[i]=false;
        }
        int ans=0;
        for(int i=0;i<nums.size();i++){
            if(map[nums[i]]){
                int c=1,j=1;
                while(map[nums[i]-j]){
                    c++;
                    map[nums[i]-j]=false;
                    j++;
                }
                j=1;
                while(map[nums[i]+j]){
                    c++;
                    map[nums[i]+j]=false;
                    j++;
                }
                ans=max(ans,c);
            }
        }
        return max(ans,1);
    }
};