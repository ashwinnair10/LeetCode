class Solution {
public:
    void dfs(vector<vector<pair<int,int>>>& adj,vector<int>& visit,int& n,int ind,int& ans){
        visit[ind]=1;
        for(int i=0;i<adj[ind].size();i++){
            if(!visit[adj[ind][i].first]){
                if(adj[ind][i].second==1)
                ans++;
                dfs(adj,visit,n,adj[ind][i].first,ans);
            }
        }
        return;
    }
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<int> visit(n,0);
        vector<vector<pair<int,int>>> adj(n);
        for(auto i:connections){
            adj[i[0]].push_back({i[1],1});
            adj[i[1]].push_back({i[0],2});
        }
        int ans=0;
        dfs(adj,visit,n,0,ans);
        return ans;
    }
};