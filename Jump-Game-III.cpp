1class Solution {
2public:
3    bool canReach(vector<int>& arr, int start) {
4        int n = arr.size();
5
6        vector<bool> visited(n, false);
7        queue<int> q;
8
9        q.push(start);
10
11        while (!q.empty()) {
12            int i = q.front();
13            q.pop();
14
15            if (i < 0 || i >= n || visited[i])
16                continue;
17
18            if (arr[i] == 0)
19                return true;
20
21            visited[i] = true;
22
23            q.push(i + arr[i]);
24            q.push(i - arr[i]);
25        }
26
27        return false;
28    }
29};