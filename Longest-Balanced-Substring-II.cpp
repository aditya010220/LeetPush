1#include <memory_resource>
2pmr::unsynchronized_pool_resource pool;
3class Solution {
4public:
5    static int has1(string& s, int n){
6        int cnt=1, len=1;
7        for(int i=1; i<n; i++){
8            if (s[i]==s[i-1]) len++;
9            else {
10                cnt=max(cnt, len);
11                len=1;
12            }
13        }
14        return max(cnt, len);
15    }
16
17    static constexpr long long bias=1<<18, shift=32;
18    inline static long long pack(int x, int y){
19        // Deal with negative int
20        return ((long long)(x+bias)<<shift)|(long long)(y+bias);
21    }
22
23    static int longestBalanced(string& s) {
24        const int n=s.size();
25        int ans=has1(s, n);
26
27        pmr::unordered_map<long long, int> ab(&pool), bc(&pool), ca(&pool), abc(&pool);
28        
29        ab.reserve(n), bc.reserve(n), ca.reserve(n), abc.reserve(n);
30        // INITIAL STATE at -1
31        abc[pack(0, 0)]=-1;
32        ab[pack(0, 0)]=-1; // (A-B, C)
33        bc[pack(0, 0)]=-1; // (B-C, A)
34        ca[pack(0, 0)]=-1; // (C-A, B)
35    
36        array<int, 3> cnt={0};
37        for(int i=0; i<n; i++){
38            cnt[s[i]-'a']++; 
39            const auto [A, B, C]=cnt;
40
41            // 3-letter balance: A=B=C
42            long long key=pack(B-A, C-A);
43            if(abc.count(key)) ans=max(ans, i-abc[key]);
44            else abc[key]=i;
45
46            // 2-letter balance: A=B and NO C
47            key=pack(A-B, C);
48            if(ab.count(key)) ans = max(ans, i-ab[key]);
49            else ab[key]=i;
50
51            // 2-letter balance: B=C and NO A
52            key=pack(B-C, A);
53            if(bc.count(key)) ans=max(ans, i-bc[key]);
54            else bc[key]=i;
55
56            // 2-letter balance: C=A and NO B
57            key=pack(C-A, B);
58            if(ca.count(key)) ans=max(ans, i-ca[key]);
59            else ca[key]=i;
60        }
61        
62        return ans;
63    }
64};
65