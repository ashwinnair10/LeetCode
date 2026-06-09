class Solution {
public:
    bool isvalid(int i,int j,int m,int n,vector<string>& matrix){
        return (i>=0&&i<m)&&(j>=0&&j<n)&&(matrix[i][j]!='#');
    }
    int minMoves(vector<string>& matrix) {
        int m=matrix.size(),n=matrix[0].length();
        if(matrix[m-1][n-1]=='#')
        return -1;
        map<char,vector<vector<int>>> map;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]!='.'&&matrix[i][j]!='#'){
                    map[matrix[i][j]].push_back({i,j});
                }
            }
        }
        vector<int> dir={1,0,-1,0,1};
        vector<vector<int>> dist(m,vector<int>(n,INT_MAX));
        set<char> set;
        deque<tuple<int,int,int>> q;
        q.push_front({0,0,0});
        dist[0][0]=0;
        while(!q.empty()){
            auto [x,y,curr]=q.front();
            q.pop_front();
            if(curr>dist[x][y])
            continue;
            if(x==m-1&&y==n-1)
            return curr;
            if(matrix[x][y]!='.'&&matrix[x][y]!='#'&&set.find(matrix[x][y])==set.end()){
                set.insert(matrix[x][y]);
                for(auto tel:map[matrix[x][y]]){
                    if(curr<dist[tel[0]][tel[1]]){
                        dist[tel[0]][tel[1]]=curr;
                        q.push_front({tel[0],tel[1],curr});
                    }
                }
            }
            for(int i=0;i<4;i++){
                if(isvalid(x+dir[i],y+dir[i+1],m,n,matrix)){
                    if(curr+1<dist[x+dir[i]][y+dir[i+1]]){
                        dist[x+dir[i]][y+dir[i+1]]=curr+1;
                        q.push_back({x+dir[i],y+dir[i+1],curr+1});
                    }
                }
            }
        }
        return -1;
    }
};