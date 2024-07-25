class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int,int> map;
        map[0]=-1;
        int p=0,q=0;
        int ans=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i])
            q++;
            else
            p++;
            if(map.find(p-q)!=map.end()){
                ans=max(ans,i-map[p-q]);
            }
            else
            map[p-q]=i;
        }
        return ans;
    }
};