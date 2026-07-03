1#include <bits/stdc++.h>
2using namespace std;
3#define ll long long
4#define all(x) (x).begin(), (x).end()
5#define pb push_back
6#define ff first
7#define ss second
8const ll mod = 1e9 + 7, MX = 2e5 + 5;
9const ll INF = 1e18;
10constexpr ll pct(int x) { return __builtin_popcount(x); }
11constexpr ll bits(int x) { return x == 0 ? 0 : 31 - __builtin_clz(x); }
12int dx[4]={0,1,0,-1};
13int dy[4]={-1,0,1,0};
14
15vector<int> topologicalSort(int n , vector<vector<int>>& g) {
16   vector<int> indeg(n, 0);
17   for (int i = 0; i < n; ++i) {
18      for (auto &adj_node : g[i])
19         ++indeg[adj_node];
20   }
21   queue<int> q;
22   vector<int> ts;
23   for (int i = 0; i < n; ++i)
24      if (!indeg[i]) q.push(i);
25
26   while (!q.empty()) {
27      int u = q.front(); q.pop();
28      ts.pb(u);
29      for (int v : g[u])
30         if (--indeg[v] == 0) q.push(v);
31   }
32   return ts;
33}
34
35class Solution {
36public:
37    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
38        int n = online.size();
39        vector<vector<pair<int,int>>> adj(n);
40        vector<vector<int>> g(n);
41        for (auto &e : edges) {
42            int u = e[0], v = e[1], c = e[2];
43            adj[u].pb({v,c});
44            g[u].pb(v);
45        }
46        vector<int> ts = topologicalSort(n, g);
47        auto ok = [&](int x){
48            vector<ll> d(n, INF);
49            d[0] = 0;
50            for (int u : ts) if (d[u] < INF) {
51                for (auto &p : adj[u]) {
52                    int v = p.ff, c = p.ss;
53                    if (c < x || !online[v]) continue;
54                    d[v] = min(d[v], d[u] + c);
55                }
56            }
57            return d[n-1] <= k;
58        };
59        if (!ok(0)) return -1;
60        int l = 0, h = 0;
61        for (auto &e : edges) h = max(h, e[2]);
62        while (l < h) {
63            int md = l + (h - l + 1) / 2;
64            if (ok(md)) l = md;
65            else h = md - 1;
66        }
67        return l;
68    }
69};