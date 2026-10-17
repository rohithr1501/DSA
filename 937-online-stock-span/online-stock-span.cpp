class StockSpanner {
private:
    stack<pair<int, int>> st; // stores {price, span}

public:
    StockSpanner() {}
    
    int next(int price) {
        int span = 1;
        
        // Accumulate spans of previous prices that are <= current price
        while (!st.empty() && st.top().first <= price) {
            span += st.top().second;
            st.pop();
        }
        
        // Push the current price and its combined span onto the stack
        st.push({price, span});
        
        return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */