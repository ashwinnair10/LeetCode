class Solution {
public:
    bool valid(int i,int j,int m,int n){
        return (i>=0&&i<m)&&(j>=0&&j<n);
    }
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        deque<pair<int,int>> q;
        int m=grid.size(),n=grid[0].size();
        vector<vector<int>> mh(m,vector<int>(n,-1));
        mh[0][0]=grid[0][0]?health-1:health;
        if(mh[0][0]<0)
        return false;
        vector<int> dir={1,0,-1,0,1};
        q.push_front({0,0});
        while(!q.empty()){
            auto [x,y]=q.front();
            q.pop_front();
            if(x==m-1&&y==n-1){
                if(mh[x][y]>=1)
                return true;
                else
                continue;
            }
            int ch=mh[x][y];
            for(int i=0;i<4;i++){
                int nx=x+dir[i],ny=y+dir[i+1];
                if(!valid(nx,ny,m,n))
                continue;
                int nh=grid[nx][ny]?ch-1:ch;
                if(nh>0&&nh>mh[nx][ny]){
                    mh[nx][ny]=nh;
                    if(grid[nx][ny])
                    q.push_back({nx,ny});
                    else
                    q.push_front({nx,ny});
                }
            }
        }
        return false;
    }
};