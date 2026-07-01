1class Solution {
2public:
3    double angleClock(int hour, int minutes) {
4        double x = hour + minutes / 60.0;
5        double diff = fmod(11.0 * x, 12.0);
6        return min(diff, 12.0 - diff) * 30.0;
7    }
8};