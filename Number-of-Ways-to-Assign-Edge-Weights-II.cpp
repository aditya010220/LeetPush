1class Solution {
2public:
3    vector<int>per,depth;
4    vector<vector<int>>up;
5    int LOG=20;
6    const int MOD=1e9+7;
7    int power(long long a,long long b){
8        long long ans=1;
9        a%=MOD;
10        while(b>0){
11            if(b&1)ans=(ans*a)%MOD;
12            a=(a*a)%MOD;
13            b>>=1;
14        }
15        return (int)ans;
16    }
17
18    int countWays(int d){
19        if(d==0)return 0;
20        return power(2,d-1);
21    }
22
23    void dfs(int node,int p,vector<vector<int>>&adj){
24        per[node]=p;
25        up[node][0]=p;
26        for(int j=1;j<LOG;j++){
27            if(up[node][j-1]!=-1)up[node][j]=up[up[node][j-1]][j-1];
28        }
29        for(auto&it:adj[node]){
30            if(it!=p){
31                depth[it]=depth[node]+1;
32                dfs(it,node,adj);
33            }
34        }
35    }
36
37    int lca(int u,int v){
38        if(depth[u]<depth[v])swap(u,v);
39        int diff=depth[u]-depth[v];
40        for(int j=0;j<LOG;j++){
41            if(diff&(1<<j))
42                u=up[u][j];
43        }
44        if(u==v)
45            return u;
46        for(int j=LOG-1;j>=0;j--){
47            if(up[u][j]!=up[v][j]){
48                u=up[u][j];
49                v=up[v][j];
50            }
51        }
52        return up[u][0];
53    }
54
55    int dist(int u,int v){
56        int L=lca(u,v);
57        int d=depth[u]+depth[v]-2*depth[L];
58        return countWays(d);
59    }
60
61    vector<int> assignEdgeWeights(vector<vector<int>>& edges, vector<vector<int>>& queries) {
62        int n=edges.size()+2;
63        vector<vector<int>>adj(n);
64        for(auto&edge:edges){
65            int u=edge[0],v=edge[1];
66            adj[u].push_back(v);
67            adj[v].push_back(u);
68        }
69        per.resize(n,-1);
70        depth.resize(n,0);
71        up.resize(n,vector<int>(LOG,-1));
72        dfs(1,-1,adj);
73        vector<int>ans;
74        for(auto&q:queries){
75            int u=q[0],v=q[1];
76            ans.push_back(dist(u,v));
77        }
78        return ans;
79    }
80};