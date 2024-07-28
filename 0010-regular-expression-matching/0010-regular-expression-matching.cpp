class Solution {
public:
    int dfs(vector<vector<int>>& dp,string& s,string& p,int i,int j){
        if(i>=s.length()&&j>=p.length())
        return 1;
        if(j>=p.length())
        return 0;
        if(i>=s.length()){
            int curr=j;
            int value=0;
            while(curr<p.length()){
                if(p[curr]=='*')
                value-=1;
                else
                value+=1;
                curr++;
            }
            return value<=0;
        }
        if(i<s.length()&&dp[i][j]!=-1)
        return dp[i][j];
        int match=(i<s.length()&&(s[i]==p[j]||p[j]=='.'));
        if(i<s.length()&&j+1<p.length()&&p[j+1]=='*'){
            dp[i][j]=dfs(dp,s,p,i,j+2)||(match&&dfs(dp,s,p,i+1,j));
            return dp[i][j];
        }
        if(match){
            dp[i][j]=dfs(dp,s,p,i+1,j+1);
            return dp[i][j];
        }
        if(i<s.length())
        dp[i][j]=0;
        return 0;
    }
    bool isMatch(string s, string p) {
        int m=s.length(),n=p.length();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return dfs(dp,s,p,0,0)?true:false;
    }
};