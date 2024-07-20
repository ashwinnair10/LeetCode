class Solution {
public:
    int ans=INT_MAX;
    unordered_map<string,int> dp;
    int test(vector<int>& a,int ind,int amt,int c){
        if(amt==0){
            return c;
        }
        if(ind==-1||amt<0)
        return INT_MAX;
        string s=to_string(ind)+"."+to_string(amt)+"."+to_string(c);
        if(dp.find(s)!=dp.end())
        return dp[s];
        for(int i=amt/a[ind];i>=0;i--){
            int k=test(a,ind-1,amt-i*a[ind],c+i);
            if(k!=INT_MAX){
                ans=min(ans,k);
            }
        }
        dp[s]=ans;
        return ans;
    }
    int coinChange(vector<int>& a, int amt) {
        sort(a.begin(),a.end());
        int res=test(a,a.size()-1,amt,0);
        return res==INT_MAX?-1:res;
    }
};