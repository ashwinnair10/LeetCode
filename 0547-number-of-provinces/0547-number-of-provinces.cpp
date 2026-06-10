class Solution {
public:
    void dfs(vector<vector<int>>& grid,vector<int>& visit,int& n,int ind){
        visit[ind]=1;
        for(int i=0;i<grid[ind].size();i++){
            if(grid[ind][i]&&!visit[i]){
                dfs(grid,visit,n,i);
            }
        }
        return;
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size(),c=0;
        vector<int> visit(n,0);
        for(int i=0;i<n;i++){
            if(!visit[i]){
                c++;
                dfs(isConnected,visit,n,i);
            }
        }
        return c;
    }
};