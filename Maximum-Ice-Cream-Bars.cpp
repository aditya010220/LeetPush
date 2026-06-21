1class Solution {
2public:
3    int maxIceCream(vector<int>& costs, int coins) {
4        int n = costs.size();
5        int k =0;
6        sort(costs.begin(),costs.end());
7        for(int i =0;i<n;i++){
8            if(coins>=costs[i]){
9                coins = coins-costs[i];
10                k++;
11            }
12            else{
13                continue;
14            }
15        }
16        return k;
17    }
18};