class Solution {
public:
    long long maxSum(vector<int>& nums, int k, int mul) {
        vector<long long> p,n;
        for(auto i:nums){
            if(i>=0)
            p.push_back(i);
            else
            n.push_back(i);
        }
        sort(p.begin(),p.end(),greater<>());
        sort(n.begin(),n.end());
        int pi=0,ni=0;
        long long ans=0;
        long long s=0;
        while(k>0){
            if(mul>=0){
                if(pi<p.size()){
                    s=max(mul*p[pi],p[pi]);
                    pi++;
                }
                else{
                    s=max(mul*n[ni],n[ni]);
                    ni++;
                }
                mul--;
                ans+=s;
            }
            else{
                if(ni<n.size()){
                    s=max(mul*n[ni],n[ni]);
                    ni++;
                }
                else{
                    s=max(mul*p[pi],p[pi]);
                    pi++;
                }
                mul--;
                ans+=s;
            }
            k--;
        }
        return ans;
    }
};