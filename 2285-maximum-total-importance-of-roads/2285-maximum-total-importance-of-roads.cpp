class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<long long> deg(n);
        for(int i=0;i<roads.size();i++){
            deg[roads[i][0]]++;
            deg[roads[i][1]]++;
        }
        long long sum=0;
        sort(deg.begin(),deg.end());
        for(long long i=0;i<n;i++){
            sum+=deg[i]*(i+1);
        }
        return sum;
    }
};