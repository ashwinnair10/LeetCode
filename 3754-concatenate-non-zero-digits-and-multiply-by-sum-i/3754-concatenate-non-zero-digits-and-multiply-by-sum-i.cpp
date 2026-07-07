class Solution {
public:
    long long sumAndMultiply(int n) {
        long long p=1,s=0,num=0;
        while(n>0){
            s+=n%10;
            if(n%10){
                num+=p*(n%10);
                p*=10;
            }
            n/=10;
        }
        return num*s;
    }
};