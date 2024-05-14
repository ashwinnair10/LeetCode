class Solution {
public:
    int maxgold(vector<vector<int>>& grid,int i,int j){
        if(i<0||i>=grid.size()||j<0||j>=grid[i].size()||!grid[i][j])
        return 0;
        int k=grid[i][j];
        grid[i][j]=0;
        int sum=k+max({maxgold(grid,i,j+1),maxgold(grid,i,j-1),maxgold(grid,i+1,j),maxgold(grid,i-1,j)});
        grid[i][j]=k;
        return sum;
    }
    int getMaximumGold(vector<vector<int>>& grid) {
        int sum=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j])
                sum=max(sum,maxgold(grid,i,j));
            }
        }
        return sum;
    }
};