class StockSpanner {
    int sz;
    stack<pair<int,int>> S;
public:
    StockSpanner() {
        sz = 0;
    }
    
    int next(int price) {
        int ans;
        sz++;
        while(S.size() && S.top().first <= price){
            S.pop();
        }
        if(S.size()){
            ans =  sz-1 - S.top().second;
        }
        else ans = sz;
        S.push({price,sz-1});
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */