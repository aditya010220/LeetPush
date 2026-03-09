1class Solution {
2public:
3    int numberOfStableArrays(int zero, int one, int limit) {
4        long long MOD = 1000000007;
5        int maxN = zero + one;
6        
7        std::vector<long long> fact(maxN + 1, 0);
8        std::vector<long long> invFact(maxN + 1, 0);
9        
10        fact[0] = 1;
11        invFact[0] = 1;
12        for (int i = 1; i <= maxN; i++) {
13            fact[i] = (fact[i - 1] * i) % MOD;
14        }
15        
16        auto power = [&](long long baseVal, long long exp) {
17            long long res = 1;
18            baseVal %= MOD;
19            while (exp > 0) {
20                if (exp & 1) res = (res * baseVal) % MOD;
21                baseVal = (baseVal * baseVal) % MOD;
22                exp >>= 1;
23            }
24            return res;
25        };
26        
27        invFact[maxN] = power(fact[maxN], MOD - 2);
28        for (int i = maxN - 1; i >= 1; i--) {
29            invFact[i] = (invFact[i + 1] * (i + 1)) % MOD;
30        }
31        
32        auto C = [&](int n, int k) -> long long {
33            if (k < 0 || k > n) return 0;
34            return fact[n] * invFact[k] % MOD * invFact[n - k] % MOD;
35        };
36        
37        auto F = [&](int N, int K, int L) -> long long {
38            if (K <= 0 || K > N) return 0;
39            long long ans = 0;
40            int maxJ = (N - K) / L;
41            for (int j = 0; j <= maxJ; j++) {
42                long long term = C(K, j) * C(N - j * L - 1, K - 1) % MOD;
43                if (j & 1) {
44                    ans = (ans - term + MOD) % MOD;
45                } else {
46                    ans = (ans + term) % MOD;
47                }
48            }
49            return ans;
50        };
51
52        int maxK = std::min(zero, one + 1);
53        std::vector<long long> fOne(maxK + 2, 0);
54        for (int k = 1; k <= maxK + 1; k++) {
55            fOne[k] = F(one, k, limit);
56        }
57        
58        long long ans = 0;
59        for (int k = 1; k <= maxK; k++) {
60            long long fz = F(zero, k, limit);
61            if (fz == 0) continue;
62            long long fo = (fOne[k - 1] + 2 * fOne[k] + fOne[k + 1]) % MOD;
63            ans = (ans + fz * fo) % MOD;
64        }
65        
66        return static_cast<int>(ans);
67    }
68};