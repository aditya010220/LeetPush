1class Robot {
2    int x; 
3    int y;
4    int width; 
5    int height; 
6    string dir; 
7public:
8    Robot(int width, int height) {
9        x = 0, y = 0, dir = "East";
10        this->width = width, this->height = height;
11    }
12    
13    void step(int num) {
14        num %= (2 * (width - 1) + 2 * (height - 1));
15        if (num == 0) {
16            num = (2 * (width - 1) + 2 * (height - 1));
17        }
18
19        while(num > 0) {
20            int nx = x, ny = y; 
21            
22            if(dir == "East") {
23                int maxX = min(x + num, width - 1); 
24                int rem = num - (maxX - x); 
25                num = rem; 
26                if(rem == 0) {
27                    x = maxX, y = ny; 
28                } else {
29                    x = maxX; 
30                    dir = "North"; 
31                }
32            }
33            else if(dir == "West") {
34                int minX = max(x - num, 0); 
35                int rem = num - (x - minX); 
36                num = rem; 
37                if(rem == 0) {
38                    x = minX, y = ny; 
39                } else {
40                    x = minX; 
41                    dir = "South"; 
42                }
43            }
44            else if(dir == "North") {
45                int maxY = min(y + num, height - 1); 
46                int rem = num - (maxY - y); 
47                num = rem; 
48                if(rem == 0) {
49                    x = nx, y = maxY; 
50                } else {
51                    y = maxY; 
52                    dir = "West"; 
53                }
54            }
55            else if(dir == "South") {
56                int minY = max(y - num, 0); 
57                int rem = num - (y - minY); 
58                num = rem; 
59                if(rem == 0) {
60                    x = nx, y = minY; 
61                } else {
62                    y = minY; 
63                    dir = "East"; 
64                }
65            }
66        }
67    }
68    
69    vector<int> getPos() {
70        return {x, y}; 
71    }
72    
73    string getDir() {
74        return dir; 
75    }
76};
77
78/**
79 * Your Robot object will be instantiated and called as such:
80 * Robot* obj = new Robot(width, height);
81 * obj->step(num);
82 * vector<int> param_2 = obj->getPos();
83 * string param_3 = obj->getDir();
84 */