class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& a) {
        int m=a.size(),n=a[0].size();
        vector<int> ans;
        vector<int> row(m,INT_MAX),col(n,INT_MIN);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++)
            row[i]=min(row[i],a[i][j]);
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++)
            col[i]=max(col[i],a[j][i]);
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(row[i]==col[j])
                ans.push_back(row[i]);
            }
        }
        return ans;
    }
};