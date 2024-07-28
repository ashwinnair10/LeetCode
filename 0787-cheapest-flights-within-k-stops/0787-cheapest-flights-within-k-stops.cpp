class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        vector<vector<int>> dp(K + 2, vector<int>(n, INT_MAX));
        dp[0][src] = 0;
        for (int i = 1; i <= K + 1; ++i) {
            dp[i][src] = 0
            for (const auto& flight : flights) {
                int u = flight[0], v = flight[1], cost = flight[2];
                if (dp[i - 1][u] != INT_MAX) {
                    dp[i][v] = min(dp[i][v], dp[i - 1][u] + cost);
                }
            }
        }
        int ans = INT_MAX;
        for (int i = 1; i <= K + 1; ++i) {
            ans = min(ans, dp[i][dst]);
        }
        return ans == INT_MAX ? -1 : ans;
    }
};