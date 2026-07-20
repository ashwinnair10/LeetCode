class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        vector<int> nums;
        for(auto i:grid){
            for(auto j:i){
                nums.push_back(j);
            }
        }
        k=k%nums.size();
        int s=nums.size()-k;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                grid[i][j]=nums[(s++)%nums.size()];
            }
        }
        return grid;
    }
};