class Solution 
{
public:
    int maximumUniqueSubarray(vector<int>& nums) 
    {
        unordered_map<int, int> freq;
        int ans = 0, n = nums.size(), l = 0, r = 0, sum = 0;
        
        while(r < n)
        {
            if(!freq[nums[r]])
                sum += nums[r], freq[nums[r++]]++;
            else
                sum -= nums[l], freq[nums[l++]]--;
       
            ans = max(ans, sum);
        }
        
        return ans;
    
    }
};
