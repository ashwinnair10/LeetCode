class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int m=INT_MIN,n=costs.size();
        for(auto i:costs)
        m=max(m,i);
        vector<int> c(m+1,0);
        for(auto i:costs)
        c[i]++;
        for(int i=1;i<m+1;i++)
        c[i]+=c[i-1];
        vector<int> res(n,0);
        for(int i=0;i<n;i++){
            res[c[costs[n-1-i]]-1]=costs[n-1-i];
            c[costs[n-1-i]]--;
        }
        int ans=0;
        for(int i=0;i<n;i++){
            if(coins>=res[i]){
                ans++;
                coins-=res[i];
            }
            else
            break;
        }
        return ans;
    }
};