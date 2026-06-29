class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int ans=0;
        for(auto i:patterns)
        if(word.contains(i))
        ans++;
        return ans;
    }
};