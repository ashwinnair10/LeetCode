class Solution {
public:
    string rem(string& input,string& tar) {
        stack<char> st;
        for (char i : input) {
            if (i == tar[1] && !st.empty() &&st.top() == tar[0]) {
                st.pop();
            } else {
                st.push(i);
            }
        }
        string res;
        while (!st.empty()) {
            res += st.top();
            st.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
    int maximumGain(string s, int x, int y) {
        int t = 0;
        string h = x > y ? "ab" : "ba";
        string l = h == "ab" ? "ba" : "ab";
        string s1 = rem(s, h);
        int rp =(s.length() - s1.length()) / 2;
        t += rp * max(x, y);
        string s2 =rem(s1, l);
        rp =(s1.length() - s2.length()) /2;
        t += rp * min(x, y);
        return t;
    }
};