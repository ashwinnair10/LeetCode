class Solution {
public:
    vector<vector<int>> filterOccupiedIntervals(vector<vector<int>>& occ, int fs, int fe) {
        sort(occ.begin(),occ.end());
        vector<vector<int>> it;
        int s=occ[0][0],e=occ[0][1];
        for(int i=1;i<occ.size();i++){
            if(occ[i][0]<=e+1){
                e=max(occ[i][1],e);
            }
            else{
                it.push_back({s,e});
                s=occ[i][0];
                e=occ[i][1];
            }
        }
        it.push_back({s,e});
        for(auto i:it)
        cout<<i[0]<<" -- "<<i[1]<<"\n";
        vector<vector<int>> ans;
        for(int i=0;i<it.size();i++){
            if(it[i][1]<fs||it[i][0]>fe){
                ans.push_back(it[i]);
            }
            else{
                if(it[i][0]<fs)
                ans.push_back({it[i][0],fs-1});
                if(it[i][1]>fe)
                ans.push_back({fe+1,it[i][1]});
            }
        }
        return ans;
    }
};