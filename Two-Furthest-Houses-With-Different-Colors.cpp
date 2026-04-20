1class Solution {
2public:
3    int maxDistance(vector<int>& colors) {
4        int n = colors.size();
5        int maxi = 0;
6
7        for(int i = 0; i < n; i++){
8            for(int j = i + 1; j < n; j++){
9                if(colors[i] != colors[j]){
10                    maxi = max(maxi, j - i);
11                }
12            }
13        }
14        return maxi;
15    }
16};