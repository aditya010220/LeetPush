class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int>temp = arr;
        sort(temp.begin(),temp.end());

        unordered_map<int ,int>mp;
        int r = 1; 

        for(auto x : temp){
            if(!mp.count(x)){
                mp[x]=r;
                r++;
            }
        }
        for(int i =0;i<arr.size();i++){
            arr[i]=mp[arr[i]];
        }
        return arr;
    }
};