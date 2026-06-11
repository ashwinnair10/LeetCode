class Solution {
public:
    void dfs(vector<vector<int>>& adj,vector<int>& visit,int ind,int& md,int l){
        visit[ind]=1;
        md=max(md,l);
        for(int i=0;i<adj[ind].size();i++){
            if(!visit[adj[ind][i]]){
                dfs(adj,visit,adj[ind][i],md,l+1);
            }
        }
        return;
    }
    int assignEdgeWeights(vector<vector<int>>& edges) {
        int n=edges.size()+1;
        vector<vector<int>> adj(n);
        for(auto i:edges){
            adj[i[0]-1].push_back(i[1]-1);
            adj[i[1]-1].push_back(i[0]-1);
        }
        vector<int> visit(n,0);
        int md=0;
        dfs(adj,visit,0,md,0);
        int ans=1;
        while(md>1){
            ans=(ans*2)%1000000007;
            md--;
        }
        cout<<"max path length : "<<md<<"\n";
        return ans;
    }
};