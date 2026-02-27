1class Solution {
2public:
3    int lengthOfLongestSubstring(string s) {
4        int maxLength = 0;
5        int left = 0;
6        unordered_map<char, int> count;
7
8        for (int right = 0; right < s.length(); right++) {
9            char c = s[right];
10            count[c] = count[c] + 1;
11            
12            while (count[c] > 1) {
13                char leftChar = s[left];
14                count[leftChar] = count[leftChar] - 1;
15                left++;
16            }
17            
18            maxLength = max(maxLength, right - left + 1);
19        }
20        
21        return maxLength;        
22    }
23};