class Solution {
public:
    void dfs(vector<vector<int>>& adj,vector<int>& vec,vector<int>& visit,int i){
        visit[i]=1;
        vec[i]=1;
        for(int j=0;j<26;j++){
            if(adj[i][j]&&!visit[j]){
                dfs(adj,vec,visit,j);
            }
        }
        return;
    }
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        vector<vector<int>> adj(26,vector<int>(26,0));
        for(int i=0;i<s1.length();i++){
            adj[s1[i]-97][s1[i]-97]=1;
            adj[s2[i]-97][s2[i]-97]=1;
            adj[s1[i]-97][s2[i]-97]=1;
            adj[s2[i]-97][s1[i]-97]=1;
        }
        vector<int> map(26,-1);
        string ans="";
        for(int i=0;i<baseStr.length();i++){
            if(map[baseStr[i]-97]!=-1){
                ans+=map[baseStr[i]-97]+97;
                continue;
            }
            vector<int> list(26,0),visit(26,0);
            list[baseStr[i]-97]=1;
            for(int j=0;j<26;j++){
                if(j!=(baseStr[i]-97)&&adj[baseStr[i]-97][j]){
                    dfs(adj,list,visit,j);
                }
            }
            for(int j=0;j<26;j++){
                if(list[j]){
                    ans+=(j+97);
                    map[baseStr[i]-97]=j;
                    break;
                }
            }
        }
        return ans;
    }
};