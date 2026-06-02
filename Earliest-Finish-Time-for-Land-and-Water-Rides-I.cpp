1class Solution {
2public:
3    int earliestFinishTime(vector<int>& startL, vector<int>& durL, vector<int>& startW, vector<int>& durW) {
4        int minL = 3000, minW = minL, res = minW;
5        int n = startL.size(), m = startW.size();
6
7        for (int i = 0; i < n; i++)
8            minL = min(minL, startL[i] + durL[i]);
9
10        for (int i = 0; i < m; i++) {
11            minW = min(minW, startW[i] + durW[i]);
12            res = min(res, max(minL, startW[i]) + durW[i]);
13        }
14
15        for (int i = 0; i < n; i++)
16            res = min(res, max(minW, startL[i]) + durL[i]);
17
18        return res;
19    }
20};