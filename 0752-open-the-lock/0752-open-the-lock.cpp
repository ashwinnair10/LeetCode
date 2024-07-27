class Solution {
public:
    int ans = INT_MAX;
    string change(string s, int ind, int p) {
        if (p) {
            s[ind] = (s[ind] == '9') ? '0' : s[ind] + 1;
        } else {
            s[ind] = (s[ind] == '0') ? '9' : s[ind] - 1;
        }
        return s;
    }
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> visit(deadends.begin(), deadends.end());
        if (visit.find("0000") != visit.end())
            return -1;
        queue<pair<string, int>> q;
        q.push({"0000", 0});
        visit.insert("0000");
        while (!q.empty()) {
            string curr = q.front().first;
            int c = q.front().second;
            q.pop();
            if (curr == target) {
                ans=min(ans,c);
                continue;
            }
            for (int i = 0; i < 4; ++i) {
                string s1 = change(curr, i, 0);
                string s2 = change(curr, i, 1);

                if (visit.find(s1) == visit.end()) {
                    q.push({s1, c + 1});
                    visit.insert(s1);
                }
                if (visit.find(s2) == visit.end()) {
                    q.push({s2, c + 1});
                    visit.insert(s2);
                }
            }
        }
        return ans==INT_MAX?-1:ans;
    }
};