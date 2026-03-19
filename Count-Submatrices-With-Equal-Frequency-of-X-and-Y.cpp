1int Sum[2][1001];
2int seenX[2][1001];
3class Solution {
4public:
5    static int numberOfSubmatrices(vector<vector<char>>& grid) {
6        const int r=grid.size(), c=grid[0].size();
7        memset(Sum[0], 0, (c+1)*sizeof(int));
8        memset(Sum[1], 0, (c+1)*sizeof(int));
9        memset(seenX[0], 0, (c+1)*sizeof(int));
10        memset(seenX[1], 0, (c+1)*sizeof(int));
11        int cnt=0;
12        for(int i=0; i<r; i++){
13            bool iEven=(i&1)==0, prv=!iEven;
14            for(int j=0; j<c; j++){
15                const char c=grid[i][j];
16                bool isX=c=='X', isY=c=='Y';
17                Sum[iEven][j+1]=isX-isY+Sum[iEven][j]+Sum[prv][j+1]-Sum[prv][j];
18                seenX[iEven][j+1]=isX+seenX[iEven][j]+seenX[prv][j+1]-seenX[prv][j];
19                cnt+=((Sum[iEven][j+1]==0) & (seenX[iEven][j+1]>0));
20            }
21        }
22        return cnt;
23    }
24};