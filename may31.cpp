class Solution {
public:
    vector<int> singleNumber(vector<int>& a) {
        unordered_set<int> set;
        vector<int> vec;
        for(auto num:a){
            if(set.find(num)==set.end()){
                set.insert(num);
            }
            else
            set.erase(num);
        }
        for(auto num:set)
        vec.push_back(num);
        return vec;
    }
};