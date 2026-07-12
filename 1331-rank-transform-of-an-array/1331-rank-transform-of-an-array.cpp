class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> v=arr;
        sort(v.begin(),v.end());
        int t=1;
        unordered_map<int,int> rank;
        for(auto i:v){
            if(rank[i]==0){
                rank[i]=t++;
            }
        }
        for(int i=0;i<arr.size();i++){
            arr[i]=rank[arr[i]];
        }
        return arr;
    }
};