1class Solution {
2public:
3    int minMoves(vector<int>& nums, int limit) {
4        int n = nums.size();
5
6        // difference array
7        vector<int> diff(2 * limit + 2, 0);
8
9        int a,b,low,high,sum;
10        for(int i = 0; i < n / 2; i++) {
11            a = nums[i];
12            b = nums[n - 1 - i];
13
14            low = min(a, b) + 1;
15            high = max(a, b) + limit;
16
17            sum = a + b;
18
19            // initially all sums need 2 moves
20            diff[2] += 2;
21            diff[2 * limit + 1] -= 2;
22
23            // one move range
24            diff[low] -= 1;
25            diff[high + 1] += 1;
26
27            // exact sum needs 0 move
28            diff[sum] -= 1;
29            diff[sum + 1] += 1;
30        }
31
32        int ans = INT_MAX;
33        int moves = 0;
34
35        // calculate prefix sum
36        for(int target = 2; target <= 2 * limit; target++) {
37            moves += diff[target];
38            ans = min(ans, moves);
39        }
40        return ans;
41    }
42};