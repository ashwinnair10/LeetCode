class Solution {
public:
    int gcd(int a,int b){
        if(!a)
        return b;
        if(!b)
        return a;
        return gcd(b,a%b);
    }
    long long gcdSum(vector<int>& nums) {
        vector<int> prefixGcd;
        int m=nums[0];
        for(int i=0;i<nums.size();i++){
            m=max(m,nums[i]);
            prefixGcd.push_back(gcd(m,nums[i]));
        }
        for(auto i:prefixGcd)
        cout<<i<<" ";
        cout<<"\n";
        sort(prefixGcd.begin(),prefixGcd.end());
        long long ans=0;
        int l=0,r=prefixGcd.size()-1;
        while(l<r){
            ans+=gcd(prefixGcd[r--],prefixGcd[l++]);
        }
        return ans;
    }
};