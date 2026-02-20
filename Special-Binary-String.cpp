1class Solution {
2public:
3    string makeLargestSpecial(string s) {
4        if (s == "") return s;
5        vector<string> ans;
6        int cnt = 0;
7        for (int i = 0, j = 0; i < s.size(); ++i) {
8            cnt += s[i] == '1' ? 1 : -1;
9            if (cnt == 0) {
10                ans.push_back("1" + makeLargestSpecial(s.substr(j + 1, i - j - 1)) + "0");
11                j = i + 1;
12            }
13        }
14        sort(ans.begin(), ans.end(), greater<string>{});
15        return accumulate(ans.begin(), ans.end(), ""s);
16    }
17};