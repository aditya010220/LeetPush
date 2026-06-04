1class Solution {
2public:
3    int waviness(int x) {
4        string s = to_string(x);
5
6        int cnt = 0;
7
8        for (int i = 1; i < (int)s.size() - 1; i++) {
9            if ((s[i] > s[i - 1] && s[i] > s[i + 1]) ||
10                (s[i] < s[i - 1] && s[i] < s[i + 1])) {
11                cnt++;
12            }
13        }
14
15        return cnt;
16    }
17
18    int totalWaviness(int num1, int num2) {
19        long long ans = 0;
20
21        for (int x = num1; x <= num2; x++) {
22            ans += waviness(x);
23        }
24
25        return ans;
26    }
27};