class Solution {
public:
    void dfs(vector<vector<int>>& adj,vector<vector<int>>& ans,vector<int>& visit,int parent,int ind){
        visit[ind]=1;
        for(int i=0;i<adj[ind].size();i++){
            if(!visit[adj[ind][i]]){
                ans[adj[ind][i]].push_back(parent);
                dfs(adj,ans,visit,parent,adj[ind][i]);
            }
        }
        return;
    }
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
        }
        vector<vector<int>> ans(n);
        for(int i=0;i<n;i++){
            vector<int> visit(n);
            dfs(adj,ans,visit,i,i);
        }
        return ans;
    }
};