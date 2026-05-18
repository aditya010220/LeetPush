1constexpr int N=5e4+1;
2bitset<N> vis;
3int q[N], front=0, back=0;
4class Solution {
5public:
6    static int minJumps(vector<int>& arr) {
7        const int n=arr.size();
8        vis.reset();
9        unordered_map<int, vector<int>> dict;
10        dict.reserve(n);
11        for(int i=0; i<n; i++) 
12            dict[arr[i]].push_back(i);
13
14        front=back=0;
15        q[back++]=0;
16        int step=0;
17        while(front<back)
18        {
19            int s=back-front;
20            while(s--)
21            {
22                int cur=q[front++];
23                if (cur==n-1) return step;
24                if(cur-1>=0 && !vis[cur-1]){
25                    q[back++]=cur-1;
26                    vis[cur-1]=1;
27                }
28                if(cur<=n && !vis[cur+1]){
29                    q[back++]=cur+1;
30                    vis[cur+1]=1;
31                }
32                for(int idx: dict[arr[cur]]){
33                    if (!vis[idx]){
34                        q[back++]=idx;
35                        vis[idx]=1;
36                    }
37                }
38                dict[arr[cur]].clear();
39            }
40            step++;
41        }
42        return -1;
43    }
44};