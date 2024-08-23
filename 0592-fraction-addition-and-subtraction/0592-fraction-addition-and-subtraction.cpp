class Solution {
public:
    int gcd(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }
    string fractionAddition(string s) {
        vector<int> num,den;
        int i = 0;
        int n = s.size();
        if (s[0] != '-') {
            s = "+" + s;
        }
        while (i < n) {
            if (s[i] == '/') {
                int j = i - 1;
                int power = 0;
                int res = 0;
                while ('0' <= s[j] && s[j] <= '9') {
                    int num = s[j] - '0';
                    res = num*pow(10, power) + res;
                    j--;
                    power++;
                }
                if (s[j] == '-') {
                    res = res * (-1);
                }
                num.push_back(res);
                j = i + 1;
                bool isneg = false;
                if (s[j] == '-') {
                    isneg = true;
                }
                res = 0;
                while ('0' <= s[j] && s[j] <= '9') {
                    int num = s[j] - '0';
                    res = res * 10 + num;
                    j++;
                }
                if (isneg) {
                    res = res * -1;
                }
                den.push_back(res);
            }
            i++;
        }
        int lcm = 1;
        for (auto itr : den) {
            lcm = itr * lcm;
        }
        int numRes = 0;
        for (int i = 0; i < num.size(); i++) {
            numRes = numRes + (lcm / den[i]) * (num[i]);
        }
        int gcdVal = gcd(abs(numRes), lcm);
        numRes /= gcdVal;
        lcm /= gcdVal;
        return to_string(numRes) + "/" +to_string(lcm);
    }
};