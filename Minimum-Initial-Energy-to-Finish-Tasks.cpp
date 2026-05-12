1class Solution {
2public:
3    int minimumEffort(vector<vector<int>>& shop) {
4        sort(shop.begin(), shop.end(), [&](vector<int>& a, vector<int>& b) {
5            return a[1] - a[0] > b[1] - b[0];
6        });
7
8        int start = shop[0][1];
9        int bal = shop[0][1] - shop[0][0];
10        int loan = 0;
11
12        for (int i = 1; i < shop.size(); i++) {
13            int cost = shop[i][0];
14            int thresh = shop[i][1];
15
16            if (bal < thresh) {
17                loan += thresh - bal;
18                bal = thresh;
19            }
20
21            bal -= cost;
22        }
23
24        return start + loan;
25    }
26};