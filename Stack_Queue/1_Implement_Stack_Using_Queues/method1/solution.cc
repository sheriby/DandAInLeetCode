#include <iostream>
#include <stack>

class MyStack {
  public:
    // method1 use stl stack
    std::stack<int> s;
    /** Initialize your data structure here. */
    MyStack() {}

    /** Push element x onto stack. */
    void push(int x) { s.push(x); }

    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int val = s.top();
        s.pop();
        return val;
    }

    /** Get the top element. */
    int top() { return s.top(); }

    /** Returns whether the stack is empty. */
    bool empty() { return s.empty(); }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */