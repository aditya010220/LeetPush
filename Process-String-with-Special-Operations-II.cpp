1class Solution {
2    typedef long long ll;
3public:
4    char processStr(string s, ll k) {
5        int n = s.size();
6        vector<ll> lens;
7        ll len = 0;
8
9        for (auto& ch : s) {
10            if (ch == '*')
11                len = max(len - 1, 0LL);
12            else if (ch == '#')
13                len *= 2;
14            else if (ch != '%')
15                len++;
16
17            lens.push_back(len);
18        }
19
20        if (k >= len) return '.';
21
22        for (int i = n - 1;; i--) {
23            switch (s[i]) {
24            case '*':
25                break;
26            case '#':
27                if (k >= lens[i] / 2)
28                    k -= lens[i] / 2;
29                break;
30            case '%':
31                k = lens[i] - 1 - k;
32                break;
33            default: // s[i] is a character
34                if (lens[i] == k + 1)
35                    return s[i];
36            }
37        }
38    }
39};