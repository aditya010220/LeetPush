1class Solution {
2public:
3    int getCommon(vector<int>& nums1, vector<int>& nums2) {
4        int result=-1;
5        int n1=nums1.size(),n2=nums2.size();
6        int i=0,j=0;
7        while(i<n1 && j<n2){
8            if(nums1[i]==nums2[j]){
9                result=nums1[i];
10                break;
11            }
12            else if(nums1[i]<nums2[j]){
13                i++;
14            }
15            else{
16                j++;
17            }
18        }
19        return result;
20    }
21};
22