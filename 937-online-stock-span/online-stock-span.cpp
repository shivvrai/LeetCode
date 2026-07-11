class StockSpanner {
public:
    stack<pair<int,int>>st;
    vector<int>ans;
    int i;
    StockSpanner() {
    i=0;
    }
    
    int next(int price) {
        int cnt=1;
        while(st.size() and price>=st.top().first){
            cnt+=st.top().second;
            st.pop();
        }
        ans.push_back(cnt);
        st.push({price,cnt});
        return cnt;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */