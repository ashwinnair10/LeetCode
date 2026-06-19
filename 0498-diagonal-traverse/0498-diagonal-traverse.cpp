class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m=mat.size(),n=mat[0].size();
        vector<vector<int>> d((m-1)+(n-1)+1);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                d[i+j].push_back(mat[i][j]);
            }
        }
        vector<int> ans;
        int p=1;
        for(int i=0;i<m+n-1;i++){
            int k=d[i].size();
            for(int j=0;j<k;j++){
                if(p)
                ans.push_back(d[i][k-1-j]);
                else
                ans.push_back(d[i][j]);
            }
            p=(p+1)%2;
        }
        return ans;
    }
};