1class Solution {
2public:
3    vector<int> sortByBits(vector<int>& arr) {
4        sort(arr.begin(),arr.end(), [](int a , int b){
5            int CountA = __builtin_popcount(a);
6            int CountB = __builtin_popcount(b);
7        
8        if(CountA!=CountB){
9            return CountA<CountB;
10        }
11          return a<b;
12    });
13
14     return arr;   
15
16    }
17    
18};