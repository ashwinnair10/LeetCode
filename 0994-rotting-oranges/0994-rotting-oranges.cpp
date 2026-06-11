class Solution {
public:
    bool valid(int i,int j,int m,int n,vector<vector<int>>& grid){
        return (i>=0&&i<m)&&(j>=0&&j<n)&&(grid[i][j]!=0);
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int count=0;
        int m=grid.size(),n=grid[0].size();
        queue<vector<int>> q;
        vector<vector<int>> visit(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    count++;
                }
                else if(grid[i][j]==2){
                    q.push({i,j,0});
                    visit[i][j]=1;
                }
            }
        }
        vector<int> dir={1,0,-1,0,1};
        while(!q.empty()){
            vector<int> v=q.front();
            q.pop();
            int x=v[0],y=v[1],time=v[2];
            if(grid[x][y]==1){
                grid[x][y]=2;
                count--;
                if(!count)
                return time;
            }
            for(int i=0;i<4;i++){
                int nx=x+dir[i],ny=y+dir[i+1];
                if(valid(nx,ny,m,n,grid)&&!visit[nx][ny]){
                    visit[nx][ny]=1;
                    q.push({nx,ny,time+1});
                }
            }
        }
        return (count==0)?0:-1;
    }
};