class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int m=arr[1]-arr[0];
        for(int i=1;i<arr.size();i++){
            m=min(arr[i]-arr[i-1],m);
        }
        vector<vector<int>> ans;
        for(int i=1;i<arr.size();i++){
            if(arr[i]-arr[i-1]==m){
                ans.push_back({arr[i-1],arr[i]});
            }
        }
        return ans;
    }
};