class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& vec) {
        sort(vec.begin(), vec.end(),[](const std::vector<int>& a, const std::vector<int>& b){return a[0]<b[0];});
        int max=0;
        for(int i=0;i<vec.size()-1;i++)
        if(vec[i+1][0]-vec[i][0]>max)
        max=vec[i+1][0]-vec[i][0];
        return max;
    }
};