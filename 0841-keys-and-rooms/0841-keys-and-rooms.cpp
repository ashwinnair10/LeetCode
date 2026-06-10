class Solution {
public:
    void dfs(vector<vector<int>>& adj,vector<int>& visit,int& n,int ind){
        visit[ind]=1;
        for(int i=0;i<adj[ind].size();i++){
            if(!visit[adj[ind][i]]){
                dfs(adj,visit,n,adj[ind][i]);
            }
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        vector<vector<int>> adj(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<rooms[i].size();j++){
                adj[i].push_back(rooms[i][j]);
            }
        }
        vector<int> visit(n,0);
        dfs(adj,visit,n,0);
        for(auto i:visit)
        if(!i)
        return false;
        return true;
    }
};