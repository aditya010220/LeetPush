1using ll = long long;
2class Solution {
3    static inline int waves[570];
4    static inline bool init = []() {
5        int j = 0;
6        for (int i = 0; i < 1000; i++) {
7            int r = i % 10;
8            int m = (i / 10) % 10;
9            int l = (i / 100) % 10;
10            if ((m > max(l, r)) | (m < min(l, r)))
11                waves[j++] = i;
12        }
13        return 0;
14    }();
15
16public:
17    ll totalWaviness(ll A, ll B) { return waveCount(B) - waveCount(A - 1); }
18
19private:
20    ll waveCount(ll num) {
21        if (num < 100) return 0;            
22        return accumulate(begin(waves), end(waves), 0LL, [&](ll a, int p) {
23            return a + countWays(num, p);
24        });
25    }
26
27    ll countWays(ll num, int pattern) {
28        ll t = pattern < 100;
29        ll count = 0, mult = 1;
30
31        for (int i = 0; mult * 100 <= num; i++) {
32            ll pre = num / (mult * 1000);
33            ll cur = (num / mult) % 1000;
34            ll suf = num % mult;
35            ll ways = 0;
36
37            if (cur > pattern)
38                ways = pre - t + 1;
39            else if (cur == pattern) {
40                ways = max(0LL, pre - t);
41                count += suf + 1;
42            } else
43                ways = max(0LL, pre - t);
44            count += ways * mult;
45            mult *= 10;
46        }
47
48        return count;
49    }
50};