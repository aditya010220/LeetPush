class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int mn = *min_element(nums.begin(), nums.end());
        int mx = *max_element(nums.begin(), nums.end());


        // this is equivalent to the 
        //  for(int x:nums){
        //     st.insert(x);
        // }


        unordered_set<int> st(nums.begin(), nums.end());
        vector<int> ans;

        for (int i = mn + 1; i < mx; i++) {
            if (!st.count(i)) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};