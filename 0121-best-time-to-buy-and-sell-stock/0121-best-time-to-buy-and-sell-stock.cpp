class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit=0;
        int buy=prices[0];
        for(int i=1;i<prices.size();i++){
            if(prices[i]<buy){
                buy=prices[i];
            }
            if(prices[i]-buy>profit){
                profit=prices[i]-buy;
            }
        }
        return profit;
    }
};