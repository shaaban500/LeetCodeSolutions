class Solution {
public:
    int countElements(vector<int>& nums) 
    {
        int ans = 0;
        sort(nums.begin(), nums.end());
        int mn = nums[0], mx = nums[nums.size() - 1];
        
        for(int i = 0 ; i < nums.size() ; i++)
        {
            if(nums[i] != mn && nums[i] != mx)
                ans++;
        }
        
        return ans;
    }
};