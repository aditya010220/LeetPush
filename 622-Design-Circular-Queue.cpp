class MyCircularQueue {
public:
    deque<int>dq;
    int capacity;
    MyCircularQueue(int k) {
        capacity=k;
    }
    
    bool enQueue(int value) {
        if(isFull()){
            return false;
        }
        dq.push_back(value);
        return true;
    }
    
    bool deQueue() {
        if(isEmpty()){
            return false;
        }
        dq.pop_front();
        return true;
    }
    
    int Front() {
        if(isEmpty()){
            return -1;
        }
        return dq.front();
    }
    
    int Rear() {
        if(isEmpty()){
            return -1;
        }
        return dq.back();
    }
    
    bool isEmpty() {
        return dq.empty();
    }
    
    bool isFull() {
        return dq.size()==capacity;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */