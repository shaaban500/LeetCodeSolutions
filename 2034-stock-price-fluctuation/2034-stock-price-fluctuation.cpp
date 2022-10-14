class StockPrice 
{
public:
    map<int, int> mp;
    multiset<int> prices;
    
    void update(int timestamp, int price)
    {
        if (mp.find(timestamp) != end(mp))
            prices.erase(prices.find(mp[timestamp]));
        
        prices.insert(price);
        mp[timestamp] = price;
    }
    int current() { return rbegin(mp)->second; }
    int maximum() { return *rbegin(prices); }
    int minimum() { return *begin(prices); }
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */