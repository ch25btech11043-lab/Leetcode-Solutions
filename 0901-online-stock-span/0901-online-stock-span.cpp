class StockSpanner {
public:
    vector<int> arr;
    StockSpanner() {
        arr={};
    }
    
    int next(int price) {
        arr.push_back(price);
        int cnt=1;
        for(int j=arr.size()-2;j>=0;j--){
            if(arr[j]<=price) cnt++;
            else break;
        }
        return cnt;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */