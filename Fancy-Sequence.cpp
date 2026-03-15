1class Fancy {
2private:
3    const int mod = 1e9 + 7;
4    vector<long long> val;
5    long long a, b;
6    long long modPow(long long x, long long y, long long mod) {
7        long long res = 1;
8        x = x % mod;
9        while (y > 0) {
10            if (y % 2 == 1) {
11                res = (res * x) % mod;
12            }
13            y = y / 2;
14            x = (x * x) % mod;
15        }
16        return res;
17    }
18public:
19    Fancy() : a(1), b(0) {
20    }
21    
22    void append(int val) {
23        long long x = (val - b + mod) % mod;
24        this->val.push_back((x * modPow(a, mod - 2, mod)) % mod);
25    }
26    
27    void addAll(int inc) {
28        b = (b + inc) % mod;
29    }
30    
31    void multAll(int m) {
32        a = (a * m) % mod;
33        b = (b * m) % mod;
34    }
35    
36    int getIndex(int idx) {
37        if (idx >= val.size()) 
38            return -1;
39        return (a * val[idx] + b) % mod;
40    }
41};