class Solution {
public:
    int minOperations(vector<int>& nums, int x)
    {
        int n = nums.size(), ans = 1e9 + 1;
        vector<int> prefixSum(n, 0), suffixSum(n, 0);

        prefixSum[0] = nums[0];
        for(int i = 1 ; i < n ; i++)
            prefixSum[i] = nums[i] + prefixSum[i - 1]; 
    
        reverse(nums.begin(), nums.end());
        
        suffixSum[0] = nums[0];
        for(int i = 1 ; i < n ; i++)
            suffixSum[i] = nums[i] + suffixSum[i - 1];
        
        reverse(nums.begin(), nums.end());

        prefixSum.push_back(1e9 + 1);
        suffixSum.push_back(1e9 + 1);
        
        for(int i = 0 ; i < n ; i++)
        {
            int needed = x - prefixSum[i];
            
            if(needed < 0)
                continue;
            
            if(needed == 0)
            {
                ans = min(ans, i + 1);
                continue;
            }
            
            int lo = lower_bound(suffixSum.begin(), suffixSum.end(), needed) - suffixSum.begin();
            
            if(i < n - lo - 1 && suffixSum[lo] == needed)
                ans = min(ans, lo + i + 2);
        }

        for(int i = 0 ; i < n ; i++)
        {
            int needed = x - suffixSum[i];
            
            if(needed < 0)
                continue;
            
            if(needed == 0)
            {
                ans = min(ans, i + 1);
                continue;
            }

            int lo = lower_bound(prefixSum.begin(), prefixSum.end(), needed) - prefixSum.begin();
            
            if(i < n - lo - 1 && prefixSum[lo] == needed)
                ans = min(ans, lo + i + 2);
        }
    
        return ans == 1e9 + 1 ? -1 : ans;
    }
};


























