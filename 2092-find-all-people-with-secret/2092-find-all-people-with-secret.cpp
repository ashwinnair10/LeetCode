class Solution {
public:
    static bool cmp(vector<int>& a,vector<int>& b){
        return a[2]<b[2];
    }
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        sort(meetings.begin(),meetings.end(),cmp);
        unordered_set<int> set;
        // for(auto i:meetings){
        //     cout<<i[0]<<' '<<i[1]<<' '<<i[2]<<'\n';
        // }
        vector<vector<pair<int,int>>> adj(n);
        for(auto i:meetings){
            adj[i[0]].push_back({i[1],i[2]});
            adj[i[1]].push_back({i[0],i[2]});
        }
        vector<int> ans;
        ans.push_back(0);
        ans.push_back(firstPerson);
        set.insert(0);
        set.insert(firstPerson);
        queue<pair<int,int>> q;
        q.push({0,0});
        q.push({firstPerson,0});
        while(!q.empty()){
            int person=q.front().first;
            int time=q.front().second;
            q.pop();
            for(auto i:adj[person]){
                if(time<=i.second&&set.find(i.first)==set.end()){
                    set.insert(i.first);
                    ans.push_back(i.first);
                    q.push(i);
                }
            }
        }
        return ans;
    }
};