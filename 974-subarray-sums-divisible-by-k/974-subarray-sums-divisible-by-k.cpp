class Solution 
{
public:
    
    int subarraysDivByK(vector<int>& nums, int k) 
    {
        int ans = 0;
        int sum = 0;
        int mp[10000000] = {};
        
        for(int i = 0 ; i < nums.size() ; i++)
        {
            mp[sum]++;
            ans += mp[sum] - 1;
            sum += nums[i];
            sum = ((sum % k) + k) % k;
        }
        mp[sum]++;
        ans += mp[sum] - 1;
        
        return ans;
    }
};