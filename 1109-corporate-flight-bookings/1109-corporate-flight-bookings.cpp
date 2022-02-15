class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) 
    {
        vector<int>v(n);
        for(int i=0 ; i<bookings.size() ; i++)
        {
            int l = bookings[i][0]-1;
            int r = bookings[i][1]-1;
            int val = bookings[i][2];
            
            v[l] += val;
            if(r+1<n) v[r+1] -=val;
        }
        for(int i=1 ; i<n ; i++)
        {
            v[i] = v[i-1] + v[i];
        }
        
        return v;
    }
};