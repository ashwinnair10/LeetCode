class Solution {
public:
    int numOfWays(int n) {
        long long x=6,y=6;
        for(int i=2;i<=n;i++){
            long long p=3*x+2*y;
            long long q=2*x+2*y;
            x=p%1000000007;
            y=q%1000000007;
        }
        return (x+y)%1000000007;
    }
};