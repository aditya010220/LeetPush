1class Solution {
2public:
3    typedef long long ll;
4    bool solve(vector<vector<int>>&grid){
5        int n=grid.size(),m=grid[0].size();
6        ll bottomSum=0,topSum=0;
7        vector<int>bottomFreq(100001,0),topFreq(100001,0);
8        for(int i=0;i<n;i++){
9            for(int j=0;j<m;j++){
10                bottomSum+=grid[i][j];
11                bottomFreq[grid[i][j]]++;
12            }
13        }
14        for(int i=0;i<n-1;i++){
15           for(int j=0;j<m;j++){
16                bottomSum-=grid[i][j];
17                bottomFreq[grid[i][j]]--;
18                topSum+=grid[i][j];
19                topFreq[grid[i][j]]++;
20           }
21           if(topSum==bottomSum)return true;
22           ll diffTop=topSum-bottomSum;
23           if(diffTop>0 && diffTop<=100000){
24              int h=i+1,w=m;
25              if(h>1 && w>1){
26                if(topFreq[diffTop])return true;
27                }
28                else if(h>1 && w==1){
29                    if(grid[0][0]==diffTop || grid[i][0]==diffTop)return true;
30                }else if(h==1 && w>1){
31                    if(grid[0][0]==diffTop || grid[0][w-1]==diffTop)return true;
32                }
33           }
34           ll diffBot=bottomSum-topSum;
35           if(diffBot>0 && diffBot<=100000){
36            int h=(n-i-1),w=m;
37            if(h>1 && w>1){
38                if(bottomFreq[diffBot])return true;
39            }else if(h>1 && w==1){
40                if(grid[i+1][0]==diffBot || grid[n-1][0]==diffBot)return true;
41            }else if(h==1 && w>1){
42                if(grid[n-1][0]==diffBot || grid[n-1][w-1]==diffBot)return true;
43            }
44           }
45        }
46        return false;
47    }
48    bool canPartitionGrid(vector<vector<int>>& grid) {
49        if(solve(grid))return true;
50        int n=grid.size(),m=grid[0].size();
51        vector<vector<int>>mat(m,vector<int>(n));
52        for(int i=0;i<n;i++){
53            for(int j=0;j<m;j++){
54                mat[j][i]=grid[i][j];
55            }
56        }
57        return solve(mat);
58    }
59};