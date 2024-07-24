class Solution {
public:
    void test(vector<int>& map,vector<pair<pair<int,int>,int>>& v,int num,int ind){
        int ans=0;
        int n=num;
        int p=1;
        if(n==0){
            v[ind]={{map[0],0},ind};
            return;
        }
        while(n){
            ans=ans+p*map[n%10];
            p*=10;
            n/=10;
        }
        v[ind]={{ans,num},ind};
        return;
    }
    static bool cmp(pair<pair<int,int>,int>& a,pair<pair<int,int>,int>& b){
        if(a.first.first==b.first.first)
        return a.second<b.second;
        return a.first.first<b.first.first;
    }
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        vector<pair<pair<int,int>,int>> v(nums.size());
        for(int i=0;i<nums.size();i++){
            test(mapping,v,nums[i],i);
        }
        sort(v.begin(),v.end(),cmp);
        // for(auto i:v){
        //     cout<<i.first.first<<' '<<i.first.second<<'\n';
        // }
        vector<int> ans;
        for(auto i:v){
            ans.push_back(i.first.second);
        }
        return ans;
    }
};