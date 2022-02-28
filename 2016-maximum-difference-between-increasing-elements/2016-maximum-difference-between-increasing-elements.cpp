class Solution {
public:
    int maximumDifference(vector<int>& nums) 
    {
        int maxDif = -1;
        int n = nums.size();
        vector<int> mn(n), mx(n);
        
        mn[0] = nums[0];
        for(int i = 1 ; i < n ; i++)
            mn[i] = min(mn[i - 1], nums[i]);
        
        mx[n - 1] = nums[n -1];
        for(int i = n - 2 ; i >= 0 ; i--)
            mx[i] = max(mx[i + 1], nums[i]);
            
        
        for(int i = 0 ; i < n ; i++)
        {
            if(mx[i] != mn[i])
                maxDif = max(maxDif, mx[i] - mn[i]);            
        }
        
        return maxDif;
    }
};