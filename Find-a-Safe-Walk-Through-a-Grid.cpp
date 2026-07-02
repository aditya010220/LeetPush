1class Solution {
2public:
3    bool findSafeWalk(vector<vector<int>>& grid, int health) {
4        int m=grid.size(),n=grid[0].size();
5        vector<vector<int>>dist(m,vector<int>(n,INT_MIN));
6        priority_queue<pair<int,pair<int,int>>>pq;
7        pq.push({health-grid[0][0],{0,0}});
8        dist[0][0]=grid[0][0];
9        int dx[4]={0,0,1,-1};
10        int dy[4]={1,-1,0,0};
11        while(!pq.empty()){
12           int h=pq.top().first,i=pq.top().second.first,j=pq.top().second.second;
13           pq.pop();
14           if(h<dist[i][j])continue;
15           for(int k=0;k<4;k++){
16            int ni=i+dx[k],nj=j+dy[k];
17            if(ni>=0 && ni<m && nj>=0 && nj<n){
18                int nh = h-grid[ni][nj];
19                if(nh>dist[ni][nj]){
20                    dist[ni][nj]=nh;
21                    pq.push({nh,{ni,nj}});
22                }
23            }
24           }
25        }
26        return dist[m-1][n-1]>=1;
27    }
28};