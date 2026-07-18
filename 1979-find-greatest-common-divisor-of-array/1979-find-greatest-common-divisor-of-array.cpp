class Solution {
public:
    int gcd(int a,int b){
        if(!a)
        return b;
        if(!b)
        return a;
        return gcd(b,a%b);
    }
    int findGCD(vector<int>& nums) {
        int p=INT_MAX,q=INT_MIN;
        for(auto i:nums){
            p=min(p,i);
            q=max(q,i);
        }
        return gcd(q,p);
    }
};