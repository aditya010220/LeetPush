1class Solution {
2public:
3    static bool canPartitionGrid(vector<vector<int>>& grid) {
4        long long Tsum=0;
5        for(auto& row : grid)
6            Tsum+=accumulate(row.begin(), row.end(), 0LL);
7        if (Tsum&1) return 0;
8        const long long target=Tsum/2;
9        const int r=grid.size(), c=grid[0].size();
10        long long rowSum=0, colSum=0;
11        for(int i=0; rowSum<target && i<r; i++){
12            rowSum+=accumulate(grid[i].begin(), grid[i].end(), 0LL);
13        }
14        if (rowSum==target) return 1;
15        for(int j=0; colSum<target && j<c; j++){
16            for(int i=0; i<r; i++) colSum+=grid[i][j];
17        }
18        return colSum==target;
19    }
20};