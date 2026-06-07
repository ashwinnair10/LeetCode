class Solution {
public:
    int sumOfGoodIntegers(int n, int k) {
        int sum=0;
        for(int x=1;x<=n+k;x++){
            if(abs(n-x)<=k){
                if((n&x)==0)
                sum+=x;
            }
        }
        return sum;
    }
};