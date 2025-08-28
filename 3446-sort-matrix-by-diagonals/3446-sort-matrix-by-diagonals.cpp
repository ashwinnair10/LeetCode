class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<int>> ans(2*n-1);
        vector<int> t(2*n-1,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                ans[n-1+i-j].push_back(grid[i][j]);
            }
        }
        for(int i=0;i<2*n-1;i++){
            if(i<n-1)
            sort(ans[i].begin(),ans[i].end());
            else
            sort(ans[i].begin(),ans[i].end(),greater<int>());
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                grid[i][j]=ans[n-1+i-j][t[n-1+i-j]++];
            }
        }
        return grid;
    }
};