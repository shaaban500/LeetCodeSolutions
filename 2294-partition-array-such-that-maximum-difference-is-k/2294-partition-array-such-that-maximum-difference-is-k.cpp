class Solution {
public:
    int partitionArray(vector<int>& nums, int k) 
    {
        int ans = 0;
        sort(nums.begin(), nums.end());
        int mn = nums[0], mx = nums[0];
        
        for(int i = 0 ; i < nums.size() ; i++)
        {
            mn = min(mn, nums[i]);
            mx = max(mx, nums[i]);
            if(mx - mn > k)
            {
                ans++;
                mn = mx = nums[i];
            }
        }
        
        return ++ans;
    }
};