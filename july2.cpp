class Solution {
public:
    vector<int> intersect(vector<int>& a, vector<int>& b) {
        unordered_map<int,int> mapa,mapb;
        for(auto i:a)
        mapa[i]++;
        for(auto i:b)
        mapb[i]++;
        vector<int> ans;
        for(auto i:mapa)
            for(int j=0;j<min(i.second,mapb[i.first]);j++)
            ans.push_back(i.first);
        return ans;
    }
};