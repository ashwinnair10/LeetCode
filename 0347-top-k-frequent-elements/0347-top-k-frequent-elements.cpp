class Solution {
public:
    struct cmp{
        bool operator()(const pair<int,int>& a,const pair<int,int>& b){
            return a.second>b.second;
        }
    };
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> map;
        for(auto i:nums)
        map[i]++;
        priority_queue<pair<int,int>,vector<pair<int,int>>,cmp> pq;
        for(auto i:map){
            pq.push(i);
            if(pq.size()>k){
                pq.pop();
            }
        }
        vector<int> ans;
        while(!pq.empty()){
            ans.push_back(pq.top().first);
            pq.pop();
        }
        return ans;
    }
};