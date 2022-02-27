class Solution 
{
public:
    int minimizedMaximum(int n, vector<int>& quantities) 
    {
        int ans=0;        
        int l = 1; 
        int r = 1e5;
        while(l <= r)
        {
            int mid = (l + r) / 2;
            int tot = check(n, quantities, mid);
            if(tot > n) l = mid + 1;
            else r = mid - 1, ans = mid;
        }
        
        return ans;
    }
    
    int check(int n, vector<int>& quantities, int mid)
    {
        int tot = 0;
        int sz = quantities.size();
        for(int i = 0 ; i < sz ; i++)
            tot += (quantities[i] / mid) + (quantities[i] % mid != 0);
        
        return tot;
    }
    
};
