#include <iostream>
#include <vector>

class MyStack {
  private:
    // method1 use a simple array
    int Capacity;
    int *element;
    int size;
    bool isPushOk() { return size < Capacity; }
    void grow() {
        Capacity = Capacity + (Capacity >> 1);
        int *newEle = new int[Capacity];
        std::copy(element, element + size, newEle);
        delete[] element;
        element = newEle;
    }

  public:
    /** Initialize your data structure here. */
    MyStack() {
        Capacity = 16;
        element = new int[Capacity];
        size = 0;
    }

    /** Push element x onto stack. */
    void push(int x) {
        if (!isPushOk()) {
            grow();
        }
        element[size++] = x;
    }

    /** Removes the element on top of the stack and returns that element. */
    int pop() { return element[--size]; }

    /** Get the top element. */
    int top() { return element[size - 1]; }

    /** Returns whether the stack is empty. */
    bool empty() { return size == 0; }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */