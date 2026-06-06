class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()==1)
        return 0;
        int a=0;
        int b=prices[0];
        for(int i=1;i<prices.size();i++){
            b=min(prices[i-1],prices[i]);
            a=max(a,a+prices[i]-b);
        }
        return a;
    }   
};