1#include <string>
2#include <vector>
3#include <unordered_set>
4using namespace std;
5
6class Solution {
7public:
8    int numberOfSpecialChars(string word) {
9        vector<int> last_lower(26, -1);
10        vector<int> first_upper(26, -1);
11        unordered_set<int> invalid;
12
13        for (int i = 0; i < word.length(); i++) {
14            char ch = word[i];
15
16            if (ch >= 'a' && ch <= 'z') {
17                int idx = ch - 'a';
18
19                last_lower[idx] = i;
20
21                if (first_upper[idx] != -1) {
22                    invalid.insert(idx);
23                }
24
25            } else {
26                int idx = ch - 'A';
27
28                if (first_upper[idx] == -1) {
29                    first_upper[idx] = i;
30                }
31            }
32        }
33
34        int special_count = 0;
35
36        for (int i = 0; i < 26; i++) {
37            if (last_lower[i] != -1 &&
38                first_upper[i] != -1 &&
39                !invalid.count(i)) {
40
41                special_count++;
42            }
43        }
44
45        return special_count;
46    }
47};