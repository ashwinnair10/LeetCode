#include <iostream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

class Solution {
    long long dp[16][11][11][2][2];
    long long counts[16][11][11][2][2];

    pair<long long, long long> solve(const string& s, int idx, int prev1, int prev2, bool is_less, bool is_started) {
        if (idx == s.length()) {
            return {0, is_started ? 1 : 0}; 
        }

        if (dp[idx][prev1][prev2][is_less][is_started] != -1) {
            return {dp[idx][prev1][prev2][is_less][is_started], counts[idx][prev1][prev2][is_less][is_started]};
        }

        long long total_waviness = 0;
        long long total_counts = 0;
        int limit = is_less ? 9 : (s[idx] - '0');

        for (int digit = 0; digit <= limit; ++digit) {
            bool next_less = is_less || (digit < limit);
            bool next_started = is_started || (digit > 0);

            int wave_contribution = 0;
            if (is_started && prev1 != 10 && prev2 != 10) {
                if (prev1 > prev2 && prev1 > digit) wave_contribution = 1;
                if (prev1 < prev2 && prev1 < digit) wave_contribution = 1;
            }

            if (!is_started && digit == 0) {
                auto [sub_wave, sub_count] = solve(s, idx + 1, 10, 10, next_less, false);
                total_waviness += sub_wave;
                total_counts += sub_count;
            } 
            else {
                auto [sub_wave, sub_count] = solve(s, idx + 1, digit, prev1, next_less, true);
                total_waviness += sub_wave + (wave_contribution * sub_count);
                total_counts += sub_count;
            }
        }

        dp[idx][prev1][prev2][is_less][is_started] = total_waviness;
        counts[idx][prev1][prev2][is_less][is_started] = total_counts;
        return {total_waviness, total_counts};
    }

    long long getTotalWavinessUpTo(long long num) {
        if (num < 100) return 0;
        string s = to_string(num);
        memset(dp, -1, sizeof(dp));
        memset(counts, -1, sizeof(counts));
        return solve(s, 0, 10, 10, false, false).first;
    }

public:
    long long totalWaviness(long long num1, long long num2) {
        return getTotalWavinessUpTo(num2) - getTotalWavinessUpTo(num1 - 1);
    }
};
