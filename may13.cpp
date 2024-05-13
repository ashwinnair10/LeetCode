class Solution {
public:
    int binary(vector<int> vec){
        int s=0;
        for(int i=0;i<vec.size();i++){
            s+=vec[i]*pow(2,vec.size()-1-i);
        }
        return s;
    }
    int matrixScore(vector<vector<int>>& grid) {
        int maxsum=0;
        for(int i=0;i<grid.size();i++){
            if(!grid[i][0]){
                for(int j=0;j<grid[i].size();j++){
                    grid[i][j]=(grid[i][j]+1)%2;
                }
            }
        }
        for(int i=1;i<grid[0].size();i++){
            int c=0;
            for(int j=0;j<grid.size();j++){
                if(!grid[j][i]){
                    c++;
                    if(c>grid.size()/2)
                    break;
                }
            }
            if(c>(grid.size()/2)){
                for(int j=0;j<grid.size();j++){
                    grid[j][i]=(grid[j][i]+1)%2;
                }
            }
        }
        for(int i=0;i<grid.size();i++){
            maxsum+=binary(grid[i]);
        }
        return maxsum;
    }
};