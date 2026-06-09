class MinStack {
public:
    vector<pair<int, int>> inner_stack;

    MinStack() {
    }
    
    void push(int val) {
        if (inner_stack.empty()) {
           inner_stack.push_back({val, val});
        }
        else {
            int current_min = min(val, inner_stack.back().second);
            inner_stack.push_back({val, current_min});
        }
    }
    
    void pop() {
        inner_stack.pop_back();
    }
    
    int top() {
        return inner_stack.back().first;
    }
    
    int getMin() {
        return inner_stack.back().second;
    }

};
