class MyQueue {
public:
    stack<int> s1, s2;

    MyQueue() {
        
    }

    // Push element to the back of queue
    void push(int x) {
        s1.push(x);
    }

    // Remove the front element
    int pop() {

        // If s2 is empty, transfer all elements from s1
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }

        int x = s2.top();
        s2.pop();
        return x;
    }

    // Get the front element
    int peek() {

        // Transfer only if needed
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }

        return s2.top();
    }

    // Check whether queue is empty
    bool empty() {
        return s1.empty() && s2.empty();
    }
};