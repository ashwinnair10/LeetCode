class Solution {
public:
    static int findTheWinner(int n, int k) {
        int a=1;
        for(int i=2; i<=n; i++)
            a=(a+(k-1))%i+1;
        return a;
    }
};