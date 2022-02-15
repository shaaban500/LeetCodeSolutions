class SeatManager
{
    public:
    
    vector<int>reserved;
    priority_queue<int>pq;
    
    SeatManager(int n) 
    {
        reserved.resize(n+1);
        
        for(int i=1 ; i<=n ; i++)
        {
            pq.push(-i);
            reserved[i] = 0;
        }
    }
    
    int reserve() 
    { 
        int t = -pq.top(); pq.pop();
        reserved[t] = 1;
        return t;
    }
    
    void unreserve(int seatNumber) 
    {
        reserved[seatNumber] = 0;
        pq.push(-seatNumber);
    }
};

