class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n=nums.size();
        int sum=0,c=0;
        unordered_map<int,int> map;
        for(int i=0;i<n;i++){
            sum=(k+(sum+nums[i])%k)%k;
            if(map.find(sum)!=map.end()){
                c+=map[sum];
                if(!sum)
                c++;
                map[sum]++;
            }
            else if(!sum){
                c++;
                map.insert(make_pair(sum,1));
            }
            else{
                map.insert(make_pair(sum,1));
            }
        }
        return c;
    }
};