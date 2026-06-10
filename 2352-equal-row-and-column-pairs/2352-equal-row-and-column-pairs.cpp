class Solution {
public:
    string tostring(vector<int>& a){
        string ans="";
        for(auto i:a){
            ans+="."+to_string(i);
        }
        return ans;
    }
    int equalPairs(vector<vector<int>>& grid) {
        unordered_map<string,int> map;
        int ans=0;
        for(auto i:grid){
            map[tostring(i)]++;
        }
        for(int j=0;j<grid[0].size();j++){
            vector<int> v;
            for(int i=0;i<grid.size();i++){
                v.push_back(grid[i][j]);
            }
            ans+=map[tostring(v)];
        }
        return ans;
    }
};