class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int s=0,m=0;
        for(auto i:gain){
            s+=i;
            m=max(m,s);
        }
        return m;
    }
};