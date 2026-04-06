1// variant using resize
2class Solution {
3public:
4    static string decodeCiphertext(string& encodedText, int rows) {
5        if (rows==1) return encodedText;
6        const int N=encodedText.size(), cols=N/rows;
7
8        string dec;
9        dec.reserve(N);
10        for (int start=0; start<cols; start++) {
11            for (int r=0, c=start; r<rows && c<cols; r++, c++) {
12                dec.push_back(encodedText[r*cols+c]);  
13            }
14        }
15        int sz=dec.size();
16        while (!dec.empty() && dec[sz-1]==' ') sz--;
17        dec.resize(sz);   
18
19        return dec;
20    }
21};