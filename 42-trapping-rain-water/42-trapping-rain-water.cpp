class Solution {
public:
    int trap(vector<int>& height) 
    {
        int sum = 0;
        int n = height.size();
        vector<int>mx(n),mn(n);
            
        int mxVal = height[0];
        for(int i = 0 ; i < n ; i++)
        {
            mxVal = max(mxVal , height[i]);        
            mx[i] = mxVal;
        } 

        int mnVal = height[n - 1];
        for(int i = n - 1 ; i >= 0 ; i--)
        {
            mnVal = max(mnVal , height[i]);        
            mn[i] = mnVal;
        }
                
        for(int i = 0 ; i < n ; i++)
        {
            
            if(mx[i] == height[i] || mn[i] == height[i]) continue;
            int x = min(mx[i] , mn[i]);
            sum += x - height[i];
        }
        return sum;
    }
    
        
};

