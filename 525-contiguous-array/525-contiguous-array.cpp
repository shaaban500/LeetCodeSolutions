class Solution {
public:
    int findMaxLength(vector<int>& nums)
    {
        map<int,int>mp;
        int n = nums.size();
        int sum = 0, mx = 0;
        mp[0] = -1;
        for(int i = 0  ; i < n ; i++)
        {
            sum += nums[i]? 1 : -1;
            
            if(mp.find(sum) != mp.end())
                mx = max(mx, i - mp[sum]);
            else
                mp[sum] = i;
        }
        return mx;
    }
};
 
    