1class Solution {
2public:
3    int largestAltitude(vector<int>& gain) {
4        int n = gain.size();
5        int altitude =0;
6        int maxi =0;
7        for(int i =0;i<n;i++){
8           altitude = gain[i]+altitude;
9           maxi = max(maxi,altitude);
10        }
11        return maxi;
12    }
13};