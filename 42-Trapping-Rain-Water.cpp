class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int>left(n);
        vector<int>right(n);
        int maxileft = height[0];
        int maxiright = height[n-1];
        int sum =0;
        for(int i =0;i<n;i++){
            maxileft = max(maxileft,height[i]);
            left[i]=maxileft;
        }
        for(int i = n-1;i>=0;i--){
            maxiright = max(maxiright , height[i]);
            right[i] = maxiright;
        }
        for(int i =0;i<n;i++){
            int a = min(left[i],right[i])-height[i];
            sum= sum+a;
        }
        return sum;
    }
};