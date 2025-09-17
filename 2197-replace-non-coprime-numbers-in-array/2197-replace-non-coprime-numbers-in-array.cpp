class Solution {
public:
    int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        vector<int> stack;
        for (int num : nums) {
            while (!stack.empty()) {
                long long top = stack.back();
                int g = gcd(top, num);
                if (g == 1) {
                    break;
                }
                stack.pop_back();
                long long lcm = (long long)(top*num) / g;
                num = (int)lcm;
            }
            stack.push_back(num);
        }
        return stack;
    }
};