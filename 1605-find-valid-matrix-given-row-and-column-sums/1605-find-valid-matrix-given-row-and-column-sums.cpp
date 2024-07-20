class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        int rows = rowSum.size();
        int col = colSum.size();
        vector<vector<int>>ans (rows, vector<int>(col));
        for (int i = 0 ; i < rows ; i++){
            for (int j = 0 ; j< col ;j++){
                ans[i][j] = min(rowSum[i], colSum[j]);
                rowSum[i] = rowSum[i] - ans[i][j];
                colSum[j] = colSum[j] - ans[i][j];
            }
        }
        return ans ; 
    }
};