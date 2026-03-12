1class Solution {
2public:
3    int components;
4    vector<int> parent, size;
5
6    int Union(int u, int v){
7        int pu = findParent(u);
8        int pv = findParent(v);
9
10        if(pu == pv) return 0;
11
12        components--;
13        if(size[pu] > size[pv]){
14            size[pu] += size[pv];
15            parent[pv] = pu;
16        }
17        else{
18            size[pv] += size[pu];
19            parent[pu] = pv;
20        }
21        return 1;
22    }
23
24    int findParent(int node){
25        if(parent[node] == node) return node;
26        return parent[node] = findParent(parent[node]);
27    }
28
29    int maxStability(int n, vector<vector<int>>& edges, int k) {
30        components = n;
31        parent.resize(n);
32        size.resize(n, 1);
33
34        for(int i = 0; i < n; i++){
35            parent[i] = i;
36        }
37
38        vector<vector<int>> must, flex;
39
40        for(auto &it : edges){
41            if(it[3] == 1) must.push_back(it);
42            else flex.push_back(it);
43        }
44
45        int mini = INT_MAX;
46
47        for(auto &it : must){
48            int u = it[0];
49            int v = it[1];
50            int w = it[2];
51
52            mini = min(mini, w);
53
54            if(!Union(u, v)){
55                return -1;
56            }
57        }
58
59        sort(flex.begin(), flex.end(), [](vector<int>& a, vector<int>& b){
60            return a[2] > b[2];
61        });
62
63        priority_queue<int, vector<int>, greater<int>> pq;
64
65        for(auto &it : flex){
66            int u = it[0];
67            int v = it[1];
68            int w = it[2];
69
70            if(Union(u, v)){
71                pq.push(w);
72            }
73        }
74
75        while(k-- && !pq.empty()){
76            int x = pq.top();
77            pq.pop();
78            mini = min(mini, 2 * x);
79        }
80
81        if(components != 1) return -1;
82
83        if(!pq.empty()){
84            return min(mini, pq.top());
85        }
86
87        return mini;
88    }
89};