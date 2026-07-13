class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        queue<int>q;
        for(int i =1;i<9;i++){
            q.push(i);
        }
        vector<int>res;
        while(!q.empty()){

            if(q.front()>=low && q.front()<=high){
                res.push_back(q.front());
            }
            int front = q.front();
            int last_digit = front%10;
            q.pop();
            if(last_digit!=9){
                int next = (front*10)+(last_digit+1);
                if(next<=high){
                    q.push(next);
                }
            }
        }
        return res;
    }
};