1class Solution {
2public:
3    int minimumDistance(vector<int>& nums) {
4        vector<array<int, 2>> V(100001, {-1, -1});
5
6        int Ans = 1e9;
7
8        for (int i = 0; i < nums.size(); i++) {
9            int x = nums[i];
10
11            if (V[x][0] == -1) {
12                V[x][0] = i;
13            } 
14            else if (V[x][1] == -1) {
15                V[x][1] = i;
16            } 
17            else {
18                // Directly using derived formula
19                Ans = min(Ans, 2 * (i - V[x][0]));
20
21                // shift window
22                V[x][0] = V[x][1];
23                V[x][1] = i;
24            }
25        }
26
27        return (Ans == 1e9) ? -1 : Ans;
28    }
29};