class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> h=heights;
        sort(h.begin(),h.end());
        int c=0;
        for(int i=0;i<h.size();i++){
            if(h[i]!=heights[i])
            c++;
        }
        return c;
    }
};