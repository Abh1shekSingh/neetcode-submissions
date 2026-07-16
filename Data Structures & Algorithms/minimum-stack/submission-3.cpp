class MinStack {
public:
    vector<pair<int, int>> arr;
    int minEle = INT_MAX;
    MinStack() {
    }
    
    void push(int val) {
        minEle = min(minEle, val);
        arr.push_back({val, minEle});
    }
    
    void pop() {
        arr.pop_back();
        if(arr.size() == 0) minEle = INT_MAX; 
        else minEle = arr.back().second;
    }
    
    int top() {
        return arr.back().first;
    }
    
    int getMin() {
        return arr.back().second;
    }
};
