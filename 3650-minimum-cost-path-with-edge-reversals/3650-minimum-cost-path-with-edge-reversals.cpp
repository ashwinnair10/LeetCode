class Solution {
public:
    struct cmp {
        bool operator()(const std::pair<int, int>& a, const std::pair<int, int>& b) {
            return a.second > b.second;
        }
    };
    int minCost(int n, vector<vector<int>>& edges) {
        int ans=INT_MAX;
        vector<vector<vector<int>>> adj(n);
        for(auto i:edges){
            adj[i[0]].push_back({i[1],i[2]});
            adj[i[1]].push_back({i[0],2*i[2]});
        }
        vector<int> visit(n,0);
        vector<int> dist(n,INT_MAX);
        priority_queue<pair<int,int>,vector<pair<int,int>>,cmp> q;
        q.push({0,0});
        dist[0]=0;
        while(!q.empty()){
            int curr=q.top().first;
            int cost=q.top().second;
            q.pop();
            visit[curr]=1;
            if(curr==n-1){
                return cost;
            }
            if(cost>dist[curr]){
                continue;
            }
            for(auto i :adj[curr]){
                if(!visit[i[0]]){
                    if(cost+i[1]<dist[i[0]]){
                        q.push({i[0],cost+i[1]});
                        dist[i[0]]=cost+i[1];
                    }
                }
            }
        }
        return -1;
    }
};