class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
       int small = *min_element(nums.begin(), nums.end());
       int large = *max_element(nums.begin(), nums.end());
        vector<int>ans;
        unordered_set<int>st;
        for(int x:nums){
            st.insert(x);
        }
        for(int i = small+1;i<large;i++){
            if(!(st.count(i))){
                ans.push_back(i);
            }
        }
        return ans;
    }
};