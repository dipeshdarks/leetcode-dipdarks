class StockSpanner {
public:
    stack<pair<int,int>> st; 
    // pair = {price, span}

    StockSpanner() {
        
    }
    
    int next(int price) {
        int span = 1;

        // Pop all previous prices <= current price
        while (!st.empty() && st.top().first <= price) {
            span += st.top().second;
            st.pop();
        }

        // Push current price with computed span
        st.push({price, span});

        return span;
    }
};