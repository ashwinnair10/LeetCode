class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& prereq) {
        vector<int> indegree(n,0);
        vector<vector<int>> adj(n,vector<int>());
        for(auto i:prereq){
            indegree[i[0]]++;
            adj[i[1]].push_back(i[0]);
        }
        queue<int> q;
        for(int i=0;i<n;i++){
            if(!indegree[i])
            q.push(i);
        }
        vector<int> visit(n,0);
        while(!q.empty()){
            int k=q.front();
            q.pop();
            visit[k]=1;
            for(auto i:adj[k]){
                indegree[i]--;
                if(indegree[i]==0)
                q.push(i);
            }
        }
        bool ans=true;
        for(auto i:visit){
            ans=ans&&(i);
        }
        return ans;
    }
};