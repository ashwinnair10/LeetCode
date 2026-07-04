class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<int> score(n,INT_MAX);
        vector<vector<pair<int,int>>> adj(n);
        for(auto i:roads){
            adj[i[0]-1].push_back({i[1]-1,i[2]});
            adj[i[1]-1].push_back({i[0]-1,i[2]});
        }
        int ans=INT_MAX;
        vector<int> visit(n,0);
        queue<int> q;
        q.push(0);
        visit[0]=1;
        while(!q.empty()){
            auto curr=q.front();
            q.pop();
            for(auto i:adj[curr]){
                ans=min(ans,i.second);
                if(!visit[i.first]){
                    q.push(i.first);
                    visit[i.first]=1;
                }
            }
        }
        return ans;
    }
};