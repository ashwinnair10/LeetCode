class Solution {
public:
    void dfs(vector<vector<int>>& adj,int& ind,int& par,vector<int>& part,int& t){
        part[ind]=t;
        for(auto i:adj[ind]){
            if(i!=par){
                dfs(adj,i,ind,part,t);
            }
        }
    }
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<vector<int>> adj(n);
        for(int i=0;i<n-1;i++){
            if(abs(nums[i]-nums[i+1])<=maxDiff){
                adj[i].push_back(i+1);
                adj[i+1].push_back(i);
            }
        }
        vector<int> part(n,-1);
        int t=0,p=-1;
        for(int i=0;i<n;i++){
            if(part[i]==-1){
                dfs(adj,i,p,part,t);
                t++;
            }
        }
        vector<bool> ans;
        for(auto i:queries)
        ans.push_back(part[i[0]]==part[i[1]]);
        return ans;
    }
};