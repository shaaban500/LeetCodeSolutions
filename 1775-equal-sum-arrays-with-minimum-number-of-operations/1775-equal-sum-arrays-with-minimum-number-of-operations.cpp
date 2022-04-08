class Solution {
public:
    
    int minOperations(vector<int>& a, vector<int>& b) 
    {
        int n = a.size();
        int m = b.size();
        
        if(n > 6 * m || m > 6 * n)
            return -1;
    
        int sum1 = 0;
        for(int i = 0 ; i < n ; i++)
            sum1 += a[i];
        
        int sum2 = 0;
        for(int i = 0 ; i < m ; i++)
            sum2 += b[i];
        
        if(sum1 == sum2)
            return 0;
        
        int dif, x;
        vector<int> v;
        
        if(sum1 > sum2)
        {
            dif = sum1 - sum2;   
            
            for(int i = 0 ; i < n ; i++)
                v.push_back(a[i] - 1);
            
            for(int i = 0 ; i < m ; i++)
                v.push_back(6 - b[i]);
            
            sort(v.rbegin(), v.rend());
            for(int i = 0 ; i < v.size() ; i++)
            {
                dif -= v[i];
                if(dif <= 0)
                    return i + 1;
            }
        
        }
        else
        {

            dif = sum2 - sum1;
    
            for(int i = 0 ; i < m ; i++)
                v.push_back(b[i] - 1);
            
            for(int i = 0 ; i < n ; i++)
                v.push_back(6 - a[i]);
            
            sort(v.rbegin(), v.rend());
            for(int i = 0 ; i < v.size() ; i++)
            {
                dif -= v[i];
                if(dif <= 0)
                    return i + 1;
            }
        }
        
        return 0;
    }
};