class Solution {
public:
    bool recurse(string s,int i,int o,vector<vector<int>>& adj){
        if(i==s.length()){
            if(!o)
            return true;
            return false;
        }
        if(o<0)
        return false;
        bool var;
        if(adj[i][o]!=-1){
            return adj[i][o]==1;
        }
        if(s[i]=='('){
            var=recurse(s,i+1,o+1,adj);
        }
        else if(s[i]==')'){
           if(!o)
           var=false;
           else
           var=recurse(s,i+1,o-1,adj);
        }
        else{
            if(!o){
                var=recurse(s,i+1,o+1,adj) || recurse(s,i+1,o,adj);
            }
            var=recurse(s,i+1,o+1,adj) || recurse(s,i+1,o,adj) || recurse(s,i+1,o-1,adj);
        }
        adj[i][o]=var?1:0;
        return adj[i][o]==1;
    }
    bool checkValidString(string s) {
        int i=0;
        int o=0;
        vector<vector<int>> adj(s.length(),vector<int>(s.length(),-1));
        return recurse(s,i,o,adj);
    }
};