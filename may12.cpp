class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<int>> vec(n-2,vector<int> (n-2,0));
        for(int i=0;i<grid.size()-2;i++){
            for(int j=0;j<grid.size()-2;j++){
                for(int k=i;k<i+3;k++){
                    for(int l=j;l<j+3;l++){
                        vec[i][j]=max(vec[i][j],grid[k][l]);
                    }
                }
            }
        }
        return vec;
    }
};