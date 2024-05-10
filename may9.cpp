class Solution {
public:
    long long maximumHappinessSum(vector<int>& vec, int k) {
        long long sum=0;
        int n=vec.size();
        sort(vec.begin(),vec.end());
        for(int i=0;i<k;i++){
            sum+=max(vec[n-i-1]-i,0);
        }
        return sum;
    }
};