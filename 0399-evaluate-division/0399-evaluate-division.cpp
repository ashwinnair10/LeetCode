class Solution {
public:
    double fin=-1;
    void dfs(vector<vector<double>>& adj,vector<int>& visit,int ind,int end,double& ans,int& find){
        if(ind>=adj.size()||visit[ind])
        return;
        if(find==1||ind==end){
            find=1;
            fin=ans;
            return;
        }
        visit[ind]=1;
        for(int i=0;i<adj.size();i++){
            if(adj[ind][i]!=0){
                ans*=adj[ind][i];
                if(!visit[i])
                dfs(adj,visit,i,end,ans,find);
                ans/=adj[ind][i];
                if(find)
                return;
            }
        }
        return;
    }
    vector<double> calcEquation(vector<vector<string>>& eq, vector<double>& val, vector<vector<string>>& que) {
        unordered_map<string,int> map;
        int n=eq.size();
        int j=0;
        for(int i=0;i<n;i++){
            if(map.find(eq[i][0])==map.end()){
                map.insert(make_pair(eq[i][0],j));
                j++;
            }
            if(map.find(eq[i][1])==map.end()){
                map.insert(make_pair(eq[i][1],j));
                j++;
            }
        }
        int k=map.size();
        vector<vector<double>> adj(k,vector<double> (k,0.0));
        for(int i=0;i<n;i++){
            adj[map[eq[i][0]]][map[eq[i][1]]]=val[i];
            adj[map[eq[i][1]]][map[eq[i][0]]]=1/val[i];
        }
        vector<double> op;
        for(int i=0;i<que.size();i++){
            if(map.find(que[i][0])==map.end()||map.find(que[i][1])==map.end()){
                op.push_back(-1);
            }
            else{
                vector<int> visit(k,0);
                double ans=1;
                int find=0;
                dfs(adj,visit,map[que[i][0]],map[que[i][1]],ans,find);
                op.push_back(fin);
                fin=-1;
            }
        }
        return op;
    }
};