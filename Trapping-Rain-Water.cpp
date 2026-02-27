1class Solution {
2public:
3    int trap(vector<int>& height) {
4        int n = height.size();
5        vector<int>left(n);
6        vector<int>right(n);
7        int max1 = 0;
8        int max2 = 0;
9        int sum = 0;
10
11        for (int i = 0; i < n; i++) {
12            max1 = max(max1, height[i]);
13            left[i] = max1;
14        }
15
16        for (int i = n - 1; i >= 0; i--) {
17            max2 = max(max2, height[i]);
18            right[i] = max2;
19        }
20
21        for (int i = 0; i < n; i++) {
22           int a =  min(left[i], right[i]) - height[i];
23            sum += a;
24        }
25
26
27        return sum;
28    }
29};
30