1class Solution {
2public:
3    int maxProfit(vector<int>& prices) {
4        int n = prices.size();
5        int mine = INT_MAX;
6        int maxi = 0;
7        for(int i =0;i<n;i++){
8            mine = min(mine , prices[i]);
9             maxi = max(maxi , prices[i]-mine);
10
11        }
12        return maxi;
13    }
14};