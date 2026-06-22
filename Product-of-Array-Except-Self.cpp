1class Solution {
2public:
3    vector<int> productExceptSelf(vector<int>& nums) {
4        int n = nums.size();
5        vector<int>left(n,1);
6        vector<int>right(n,1);
7        vector<int>result(n,0);
8
9        for(int i =1;i<n;i++){
10            left[i]=left[i-1]*nums[i-1];
11        }
12        for(int i =n-2;i>=0;i--){
13            right[i]=right[i+1]*nums[i+1];
14        }
15        for(int i =0;i<n;i++){
16            result[i]=left[i]*right[i];
17        }
18        return result;
19    }
20};