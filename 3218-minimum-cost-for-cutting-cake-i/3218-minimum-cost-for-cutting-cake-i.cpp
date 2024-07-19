class Solution {
public:
    
    int memo[21][21][21][21];
    int solve(vector<int>& hCut, vector<int>& vCut, int si, int sj, int ei, int ej){
        if((ei - si == 1) && (ej - sj == 1)) return 0;
        
        if(memo[si][sj][ei][ej] != -1) return memo[si][sj][ei][ej];
        
        int ans = INT_MAX/2;
        
        // h-cut
        for(int ni=si+1;ni<ei;ni++){
            int cost = hCut[ni-1] + solve(hCut, vCut, si, sj, ni, ej) + solve(hCut, vCut, ni, sj, ei, ej);
            
            ans = min(ans, cost);
        }
        
        // v-cut
        for(int nj=sj+1;nj<ej;nj++){
            int cost = vCut[nj-1] + solve(hCut, vCut, si, sj, ei, nj) + solve(hCut, vCut, si, nj, ei, ej);
            
            ans = min(ans, cost);
        }
        
        return memo[si][sj][ei][ej]=ans;
    }
    
    int minimumCost(int m, int n, vector<int>& horizontalCut, vector<int>& verticalCut) {
        memset(memo,-1,sizeof(memo));
        
        return solve(horizontalCut, verticalCut, 0, 0, m, n);
    }
};