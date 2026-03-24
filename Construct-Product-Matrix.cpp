1class Solution {
2public:
3   typedef long long ll;
4    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
5        int n=grid.size(),m=grid[0].size(), mod=12345;;
6        vector<vector<int>>ans(n,vector<int>(m));
7        ll pref=1,suff=1;
8        for(int i=0;i<n;i++){
9            for(int j=0;j<m;j++){
10                ans[i][j]=pref;
11                pref=(pref*grid[i][j])%mod;
12            }
13        }
14        for(int i=n-1;i>=0;i--){
15            for(int j=m-1;j>=0;j--){
16                ans[i][j]=(ans[i][j]*suff)%mod;
17                suff=(suff*grid[i][j])%mod;
18            }
19        }
20        return ans;
21    }
22};