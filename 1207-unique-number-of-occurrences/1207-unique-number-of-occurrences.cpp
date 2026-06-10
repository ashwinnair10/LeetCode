class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> map;
        unordered_set<int> set;
        for(auto i:arr)
        map[i]++;
        for(auto i:map){
            if(set.find(i.second)!=set.end())
            return false;
            set.insert(i.second);
        }
        return true;
    }
};