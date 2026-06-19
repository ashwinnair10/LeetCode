class Solution {
public:
    map<int,vector<int>> mp ;
    int s=0 ; 
    Solution(vector<vector<int>>& rects) {
        for(auto i:rects){
            int a=(i[3]-i[1]+1)*(i[2]-i[0]+1);
            s+=a;
            mp[s]=i;
        }
    }
    
    vector<int> pick() {
        int r=rand()%s;
        vector<int> rec=mp.upper_bound(r)->second;
        int x=rand()%(rec[2]-rec[0]+1)+rec[0];
        int y=rand()%(rec[3]-rec[1]+1)+rec[1];
        return {x,y};
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(rects);
 * vector<int> param_1 = obj->pick();
 */