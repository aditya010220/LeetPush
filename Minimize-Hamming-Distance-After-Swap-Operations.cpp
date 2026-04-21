1class Solution {
2public:
3    vector<int> parent;
4
5    int find(int x) {
6        if (parent[x] != x) parent[x] = find(parent[x]);
7        return parent[x];
8    }
9
10    void unite(int a, int b) {
11        parent[find(a)] = find(b);
12    }
13
14    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
15        int n = source.size();
16        parent.resize(n);
17        iota(parent.begin(), parent.end(), 0);
18
19        for (auto& swap : allowedSwaps) {
20            unite(swap[0], swap[1]);
21        }
22
23        // Group source values by their component root
24        unordered_map<int, unordered_map<int, int>> groups;
25        for (int i = 0; i < n; i++) {
26            groups[find(i)][source[i]]++;
27        }
28
29        int hammingDist = 0;
30        for (int i = 0; i < n; i++) {
31            int root = find(i);
32            auto& freq = groups[root];
33            if (freq.count(target[i]) && freq[target[i]] > 0) {
34                freq[target[i]]--;  // matched, consume this source value
35            } else {
36                hammingDist++;      // no match found in this component
37            }
38        }
39
40        return hammingDist;
41    }
42};