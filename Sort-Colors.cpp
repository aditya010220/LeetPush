1class Solution {
2public:
3    void sortColors(vector<int>& nums) {
4        int n = nums.size();
5        int cnt0 =0;
6        int cnt1 = 0;
7        int cnt2 =0;
8        for(int i =0;i<n;i++){
9            if(nums[i]==0){
10                cnt0++;
11            }
12            else if (nums[i]==1){
13                cnt1++;
14            }
15            else{
16                cnt2++;
17            }
18            
19            
20        }
21        int i =0;
22        while(cnt0>0){
23            
24            nums[i]=0;
25            i++;
26            cnt0--;
27        }
28         while(cnt1>0){
29            nums[i]=1;
30            i++;
31            cnt1--;
32        }
33         while(cnt2>0){
34            nums[i]=2;
35            i++;
36            cnt2--;
37        }
38    }
39   
40};