class Solution {
public:
    int test(int n){
        int count=0;
        int sum=0,factor;
        for(int i=1;i*i<=n;i++){
            if(n%i==0){
                count++;
                factor=i;
                sum+=i+(n/i);
            }
        }
        if(count==2&&factor!=n/factor){
            return sum;
        }
        return 0;
    }
    int sumFourDivisors(vector<int>& nums) {
        int ans=0;
        for(auto i:nums){
            ans+=test(i);
        }
        return ans;
    }
};