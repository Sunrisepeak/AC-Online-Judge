class CQueue {
public:
    CQueue() {

    }
    
    void appendTail(int value) {
        in.push(value);
    }
    
    int deleteHead() {
        if (in.empty() && out.empty()) return -1;
        if (out.empty()) inToOut();
        int t = out.top();
        out.pop();
        return t;
    }

private:
    stack<int> in, out;

    void inToOut() {
        while (!in.empty()) {
            out.push(in.top());
            in.pop();
        }
    }
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */
