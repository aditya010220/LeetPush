1class Solution {
2    static const int n = 1000005;
3    static inline int prime[n];
4    static inline int version = 0;
5    static inline bool init = []() {
6        prime[0] = -1;
7        prime[1] = -1;
8        for (int i = 2; i <= 1000; i++)
9            if (prime[i] == 0)
10                for (int j = i * i; j < n; j += i)
11                    prime[j] = -1;
12        return true;
13    }();
14
15public:
16    int minJumps(vector<int>& nums) {
17        int len = nums.size();
18        int max = *max_element(nums.begin(), nums.end());
19
20        vector<int> head(max + 1, -1);
21        vector<int> next(len);
22
23        for (int i = 0; i < len; i++) {
24            next[i] = head[nums[i]];
25            head[nums[i]] = i;
26        }
27
28        vector<int> dp(len, -1);
29        dp[0] = 0;
30
31        queue<int> queue;
32        queue.push(0);
33
34        version++;
35
36        while (!queue.empty()) {
37            int dq = queue.front();
38            queue.pop();
39
40            if (dq == len - 1)
41                return dp[dq];
42
43            int right = dq + 1;
44            if (right < len && dp[right] == -1) {
45                dp[right] = dp[dq] + 1;
46                queue.push(right);
47            }
48
49            int left = dq - 1;
50            if (left >= 0 && dp[left] == -1) {
51                dp[left] = dp[dq] + 1;
52                queue.push(left);
53            }
54
55            int val = nums[dq];
56            if (prime[val] != -1 && prime[val] != version) {
57                prime[val] = version;
58                for (int i = val; i <= max; i += val) {
59                    for (int j = head[i]; j != -1; j = next[j]) {
60                        if (dp[j] == -1) {
61                            dp[j] = dp[dq] + 1;
62                            queue.push(j);
63                        }
64                    }
65                    head[i] = -1;
66                }
67            }
68        }
69
70        return -1;
71    }
72};