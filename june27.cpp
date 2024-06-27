class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        unordered_map<int,int> map;
        for(int i=0;i<edges.size();i++){
            map[edges[i][0]]++;
            map[edges[i][1]]++;
        }
        for(auto num:map)
        if(num.second==edges.size())
        return num.first;
        return 0;
    }
};