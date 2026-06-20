1class Solution {
2public:
3    int maxProfit(vector<int>& prices) {
4       int n = prices.size();
5       int profit=0;
6       int maxi = INT_MIN;
7       int small=INT_MAX;
8       for(int i =0;i<n;i++){
9        if(small>prices[i]){
10            small = prices[i];
11        }
12        profit = prices[i]-small;
13        maxi = max(maxi,profit);
14       }
15       return maxi;
16    }
17};
18