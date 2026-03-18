1class Solution {
2public:
3    static int countSubmatrices(vector<vector<int>>& grid, int k) {
4        const int r=grid.size(), c=grid[0].size();
5        int cnt=0, brCol=c;
6        if (grid[0][0]>k) return 0;// early stop
7        cnt++;
8        for(int j=1; j<c; j++){
9            int& x=grid[0][j];
10            x+=grid[0][j-1];
11            if(x>k)// no need for computing for the rest cols
12                { brCol=j; break;}
13            cnt++;
14        }
15        for(int i=1; i<r; i++){
16            grid[i][0]+=grid[i-1][0];
17            if (grid[i][0]>k) break;
18            cnt++;
19            for(int j=1; j<brCol; j++){
20                int& x=grid[i][j];
21                x+=grid[i-1][j]+grid[i][j-1]-grid[i-1][j-1];
22                if (x>k){
23                    brCol=j; break;
24                }
25                cnt++;
26            }
27        }
28        return cnt;
29    }
30};