class Solution {
public:
    int maxNumberOfBalloons(string text) {
        vector<int> a(26,0);
        for(auto i:text)
        a[i-'a']++;
        int ans=min({a[0],a[1],a[13],a[11]/2,a[14]/2});
        return ans;
    }
};