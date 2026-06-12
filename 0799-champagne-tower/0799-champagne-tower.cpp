class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<vector<double>> tower(102,vector<double>(102,0));
        tower[0][0]=poured;
        for(int i=0;i<=query_row;i++){
            for(int j=0;j<=i;j++){
                if(tower[i][j]>1){
                    double e=(tower[i][j]-1)/2;
                    tower[i][j]=1;
                    tower[i+1][j]+=e;
                    tower[i+1][j+1]+=e;
                }
            }
        }
        return tower[query_row][query_glass];
    }
};