class Solution {
public:
    
    bool can(int mid, vector<int>& dist, double hour)
    {
        int sum = 0;
        int n = dist.size();
        for(int i = 0 ; i < n - 1 ; i++)
            sum += dist[i] / mid + (dist[i] % mid != 0);
        
        double tot = 1.0 * sum + 1.0 * dist[n - 1] / mid;
        
        return tot <= hour;
    }
    
    int minSpeedOnTime(vector<int>& dist, double hour)
    {
        int l = 1, r = 1e8;
        int ans = -1;
        while(l <= r)
        {
            int mid = (l + r) / 2;
            if(can(mid, dist, hour)) {ans = mid, r = mid - 1;}else l = mid + 1;    
            cout << l << " "<<r<<endl;
        }
        
        return ans;
    }
};

/*
        binary search solution
        
        for(int i = 0 ; i < 50 ; i++)
        {
            int mid = (l + r) / 2;
            (can(mid, dist, hour))? r = mid : l = mid;
        }
        
*/
























