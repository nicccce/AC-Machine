// 
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

class MyQueue {
private:
    stack<int> inStack, outStack;
    
    void inToOut() {
        if (outStack.empty()) {
            while (!inStack.empty()) {
                outStack.push(inStack.top());
                inStack.pop();
            }
        }
    }
    
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        inStack.push(x);
    }
    
    int pop() {
        inToOut();
        int x = outStack.top();
        outStack.pop();
        return x;
    }
    
    int peek() {
        inToOut();
        return outStack.top();
    }
    
    bool empty() {
        return inStack.empty() && outStack.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */