class Solution {
public:
    int minSwaps(vector<int>& a) 
    {
        int n = a.size();
        
        int o = 0;
        for(int i=0 ; i<n ; i++)
            o += (a[i]==1);
        
        int z = 0;
        for(int i=0 ; i<o; i++)
            z += (!a[i]);
        
        
        int mn=z,l=1,r=o,k=z;
        while(l<n)
        {
            r = r%n;
            if(a[r]==0) k++;
            if(a[l-1]==0) k--;
            mn = min(k,mn);
            l++,r++;
        }
        
        return mn;
        
        
    }
};