// Problem Link :- https://leetcode.com/problems/online-stock-span/ 


class StockSpanner {
public:

    stack< pair<int,int> > s;
    int count = 0;

    StockSpanner() {
        
    }
    
    int next(int price) {
        while(s.size() && s.top().first <= price)
            s.pop();

        if(s.size()){
            int temp = count - s.top().second;
            s.push({price, count});
            count++;
            return temp;
        }
        
        s.push({price, count}), count++;
        return count;
    }
};

/**
 * Your stockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
