class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string,int> map;
        for(auto i:arr)
        map[i]++;
        int s=0;
        for(auto i:arr){
            if(map[i]==1){
                s++;
                if(s==k)
                return i;
            }
        }
        return "";
    }
};