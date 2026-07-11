class Solution {
public:
    void dfs(vector<vector<int>>& adj,vector<int>& comp,int ind,int& t,vector<vector<int>>& components,int& e){
        comp[ind]=t;
        if(t==components.size())
        components.push_back({});
        components[t].push_back(ind);
        for(auto i:adj[ind]){
            if(comp[i]==-1){
                e++;
                dfs(adj,comp,i,t,components,e);
            }
        }
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        vector<int> comp(n,-1);
        vector<vector<int>> components;
        int t=0;
        for(auto i:edges){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        for(int i=0;i<n;i++){
            int e=0;
            if(comp[i]==-1){
                dfs(adj,comp,i,t,components,e);
                t++;
                cout<<"edges : "<<e<<"\n";
            }
            e=0;
        }
        int ans=0;
        for(auto i:components){
            bool f=true;
            for(auto j:i){
                if(adj[j].size()!=i.size()-1){
                    f=false;
                    break;
                }
                cout<<j<<" ";
            }
            if(f)
            ans++;
            cout<<"\n";
        }
        return ans;
    }
};