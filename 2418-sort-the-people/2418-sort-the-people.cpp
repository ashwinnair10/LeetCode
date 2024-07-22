class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        unordered_map<int,string> map;
        unordered_map<int,int> height;
        for(int i=0;i<names.size();i++){
            map[i]=names[i];
            height[heights[i]]=i;
        }
        sort(heights.begin(),heights.end());
        vector<string> ans;
        for(int i=heights.size()-1;i>=0;i--){
            ans.push_back(map[height[heights[i]]]);
        }
        return ans;
    }
};