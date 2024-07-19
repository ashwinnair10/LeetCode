class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& pre) {
        vector<int> order;
        vector<int> indegree(n);
        vector<vector<int>> adj(n);
        unordered_set<int> set;
        for(auto i:pre){
            indegree[i[0]]++;
            adj[i[1]].push_back(i[0]);
            set.insert(i[0]);
            set.insert(i[1]);
        }
        queue<int> q;
        for(int i=0;i<n;i++)
        if(!indegree[i])
        q.push(i);
        while(!q.empty()){
            int curr=q.front();
            order.push_back(curr);
            q.pop();
            for(auto i:adj[curr]){
                indegree[i]--;
                if(!indegree[i])
                q.push(i);
            }
        }
        return order;
    }
};