class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        set<vector<int>> v;
        vector<vector<int>> vec;
        if(nums.size()<=3)
        return vec;
        for(int i=0;i<nums.size()-3;i++){

            for(int j=i+1;j<nums.size()-2;j++){
                int k=j+1,l=nums.size()-1;
                while(k<l){
                    long s=(long)nums[i]+nums[j]+nums[k]+nums[l];
                    if(s==target){
                        if(v.find({nums[i],nums[j],nums[k],nums[l]})==v.end()){
                            v.insert({nums[i],nums[j],nums[k],nums[l]});
                            vec.push_back({nums[i],nums[j],nums[k],nums[l]});
                            while(k<l&&k+1<nums.size()&&nums[k]==nums[k+1])
                            k++;
                            while(k<l&&nums[l]==nums[l-1])
                            l--;
                        }
                        else{
                            k++;
                            l--;
                        }
                    }
                    else if(s<target)
                    k++;
                    else
                    l--;
                }
                while(j+1<nums.size()&&nums[j]==nums[j+1])
                j++;
            }
            while(i+1<nums.size()&&nums[i]==nums[i+1])
            i++;   
        }
        return vec;
    }
};