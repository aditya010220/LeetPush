1#include <memory_resource>
2// 1-based indexed segmented tree defined recursively
3static constexpr int N=1<<17; // enough for 5*10^4
4int seg[N]; // as global variable
5
6struct segTree {
7    unsigned n;
8    segTree(vector<int>& A) : n(A.size()) {
9        build(A, 1, 0, n-1); 
10    }
11    void build(vector<int>& A, int idx, int l, int r) {
12        if (l==r) {
13            seg[idx]=A[l];
14            return;
15        }
16        const int m=(l+r)>>1;
17        build(A, 2*idx, l, m);
18        build(A, 2*idx+1, m+1, r);
19        seg[idx]=max(seg[2*idx], seg[2*idx+1]);
20    }
21
22    // Recursive update
23    void update(int idx, int l, int r, int pos, int val) {
24        if (l==r) {
25            seg[idx]=val; // Update the leaf node
26            return;
27        }
28        const int m=(l+r)>>1;
29        if (pos<=m) 
30            update(2*idx, l, m, pos, val);
31        else 
32            update(2*idx+1, m+1, r, pos, val);
33            
34        seg[idx]=max(seg[2*idx], seg[2*idx + 1]);
35    }
36
37    // Range Query for [ql, qr]
38    int query(int idx, int l, int r, int ql, int qr) {
39        if (ql>r || qr<l) return 0;
40        if (ql<=l && r <= qr) return seg[idx];
41        
42        const int m=(l+r)>>1;
43        return max(query(2*idx, l, m, ql, qr), query(2*idx+1, m+1, r, ql, qr));
44    }
45};
46// 4MB space for 5*10^4 tree nodes
47byte pool[4000000];
48class Solution {
49public:
50    static vector<bool> getResults(vector<vector<int>>&  queries) 
51    {
52        pmr::monotonic_buffer_resource MEM(pool, sizeof(pool));
53        pmr::set<int> obSet(&MEM); 
54        obSet.insert(0);//sential
55
56        // Collect all obstacles
57        const int qz=queries.size();
58        int Sz=qz;
59        int M=0;
60        for(auto& q: queries){
61            const int t=q[0], x=q[1];
62            if (t==1){
63                Sz--;
64                obSet.insert(x);
65                M=max(M, x);
66            }
67        } 
68        vector<bool> ans(Sz, 0);      
69        // Initialize base array with gaps between all obstacles
70        vector<int> A(M+1, 0);
71        int prvX=0;
72        for (auto it=next(obSet.begin()); it!=obSet.end(); it++) {
73            const int x=*it, diff=x-prvX;
74            A[x]=diff;
75            prvX=x;
76        }
77        
78        // Build the segment tree
79        segTree tree(A);
80        
81        // Process queries in reverse order
82        for (int i=qz-1, j=Sz-1; i>=0; i--) {
83            const auto& q=queries[i];
84            const int t=q[0], x=q[1];
85            auto it=obSet.lower_bound(x);
86            
87            if (t==1) {
88                auto nxt=next(it);
89                auto prv=prev(it);
90                // Update the next obstacle's gap 
91                if (nxt!=obSet.end()) {
92                    tree.update(1, 0, M, *nxt, *nxt-*prv);
93                }
94                // removed obstacle
95                tree.update(1, 0, M, *it, 0);
96                obSet.erase(it);
97            }
98            else {
99                const int sz=q[2];
100                auto prv=prev(it);
101                // Check trailing space OR the max gap from the Segment Tree
102                ans[j--]=(x-*prv>=sz||tree.query(1, 0, M, 0, x)>=sz);
103            }
104        }
105        return ans;
106    }
107};
108auto init = []() {
109    ios::sync_with_stdio(false);
110    cin.tie(nullptr);
111    cout.tie(nullptr);
112    return 'c';
113}();