class Solution {
public:
    bool valid(int& i,int& j,vector<vector<char>>& maze){
        return (i>=0&&i<=maze.size()-1)&&(j>=0&&j<=maze[0].size()-1)&&(maze[i][j]=='.');
    }
    bool validExit(int& i,int& j,vector<vector<char>>& maze,vector<int>& entrance){
        return (i!=entrance[0]||j!=entrance[1])&&(i==0||i==maze.size()-1||j==0||j==maze[0].size()-1)&&(maze[i][j]=='.');
    }
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        vector<int> dir{1,0,-1,0,1};
        vector<vector<int>> visit(maze.size(),vector<int>(maze[0].size(),0));
        queue<vector<int>> q;
        q.push({entrance[0],entrance[1],0});
        visit[entrance[0]][entrance[1]]=1;
        while(!q.empty()){
            auto v=q.front();
            int x=v[0],y=v[1],steps=v[2];
            // cout<<"x : "<<x<<" , y : "<<y<<" , steps : "<<steps<<"\n";
            q.pop();
            if(validExit(x,y,maze,entrance))
                return steps;
            for(int i=0;i<4;i++){
                int nx=x+dir[i],ny=y+dir[i+1];
                if(valid(nx,ny,maze)&&!visit[nx][ny]){
                    visit[nx][ny]=1;
                    q.push({nx,ny,steps+1});
                }
            }
        }
        return -1;
    }
};