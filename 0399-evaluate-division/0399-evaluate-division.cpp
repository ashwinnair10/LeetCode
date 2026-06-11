class Solution {
public:
    bool dfs(vector<vector<pair<int,double>>>& adj,vector<double>& ans,vector<int>& visit,int ind,int target,double mul){
        if(ind==target){
            ans.push_back(mul);
            return true;
        }
        bool flag=false;
        visit[ind]=1;
        for(int i=0;i<adj[ind].size();i++){
            if(!visit[adj[ind][i].first]){
                flag=flag||dfs(adj,ans,visit,adj[ind][i].first,target,mul*adj[ind][i].second);
            }
        }
        visit[ind]=0;
        return flag;
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        int t=0;
        unordered_map<string,int> map;
        vector<vector<pair<int,double>>> adj;
        for(int i=0;i<equations.size();i++){
            if(map.find(equations[i][0])==map.end()){
                map[equations[i][0]]=t++;
                adj.push_back({});
            }
            if(map.find(equations[i][1])==map.end()){
                map[equations[i][1]]=t++;
                adj.push_back({});
            }
            adj[map[equations[i][0]]].push_back({map[equations[i][1]],values[i]});
            adj[map[equations[i][1]]].push_back({map[equations[i][0]],1/values[i]});
        }
        vector<double> ans;
        vector<int> visit(map.size(),0);
        for(auto i:queries){
            if(map.find(i[0])==map.end()||map.find(i[1])==map.end()){
                ans.push_back(-1);
            }
            else{
                if(!dfs(adj,ans,visit,map[i[0]],map[i[1]],1))
                ans.push_back(-1);
            }
        }
        return ans;
    }
};