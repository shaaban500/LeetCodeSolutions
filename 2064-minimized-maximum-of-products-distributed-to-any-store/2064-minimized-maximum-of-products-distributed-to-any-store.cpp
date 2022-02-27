class Solution 
{
public:
    int minimizedMaximum(int n, vector<int>& quantities) 
    {
        int ans=0;
        int sz = quantities.size();
        int l = 1, r = 1e5;
        while(l <= r)
        {
            int mid = (l + r) / 2;
            int tot = 0;
            for(int i = 0 ; i < sz ; i++)
            {
                tot += (quantities[i] / mid) + (quantities[i] % mid != 0);
            }
            cout << l << " " << r << " " << mid << " "<< tot<< endl;
            if(tot > n) l = mid + 1;
            if(tot <= n) r = mid - 1,ans = mid;
        }
        
        return ans;
    }
};


/*

    l,r
    mid
    check
    



*/