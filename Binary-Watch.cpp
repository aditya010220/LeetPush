1class Solution {
2public:
3    vector<string> readBinaryWatch(int turnedOn) {
4        vector<string> result;
5        
6        for (int hour = 0; hour < 12; hour++) {
7            for (int minute = 0; minute < 60; minute++) {
8                
9                if (__builtin_popcount(hour) + __builtin_popcount(minute) == turnedOn) {
10                    
11                    string time = to_string(hour) + ":";
12                    
13                    if (minute < 10) {
14                        time += "0";
15                    }
16                    
17                    time += to_string(minute);
18                    
19                    result.push_back(time);
20                }
21            }
22        }
23        
24        return result;
25    }
26};