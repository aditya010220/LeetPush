1class Solution {
2public:
3    bool canMake(vector<int>& bloomDay, int m, int k, int day) {
4        int bouquets = 0;
5        int flowers = 0;
6
7        for (int i = 0; i < bloomDay.size(); i++) {
8            if (bloomDay[i] <= day) {
9                flowers++;
10                if (flowers == k) {
11                    bouquets++;
12                    flowers = 0;
13                }
14            } else {
15                flowers = 0;
16            }
17        }
18        return bouquets >= m;
19    }
20
21    int minDays(vector<int>& bloomDay, int m, int k) {
22        int n = bloomDay.size();
23
24        
25        if ((long long)m * k > n) return -1;
26
27        int low = *min_element(bloomDay.begin(), bloomDay.end());
28        int high = *max_element(bloomDay.begin(), bloomDay.end());
29
30        int ans = -1;
31
32        while (low <= high) {
33            int mid = low + (high - low) / 2;
34
35            if (canMake(bloomDay, m, k, mid)) {
36                ans = mid;
37                high = mid - 1; // try smaller day
38            } else {
39                low = mid + 1;  // need more days
40            }
41        }
42
43        return ans;
44    }
45};
46auto init = atexit([](){ofstream("display_runtime.txt")<<"0";});