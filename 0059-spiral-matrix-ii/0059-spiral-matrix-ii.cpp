class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n,vector<int>(n));
        int ru=0,rl=n-1,cu=0,cl=n-1;
        int val=1;
        while(ru<=rl&&cu<=cl){
            for(int i=cu;i<=cl;i++){
                ans[ru][i]=val++;
            }
            ru++;
            for(int i=ru;i<=rl;i++){
                ans[i][cl]=val++;
            }
            cl--;
            for(int i=cl;i>=cu;i--){
                ans[rl][i]=val++;
            }
            rl--;
            for(int i=rl;i>=ru;i--){
                ans[i][cu]=val++;
            }
            cu++;
        }
        return ans;
    }
};