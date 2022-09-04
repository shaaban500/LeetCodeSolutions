class Solution {
public:
    bool findSubarrays(vector<int>& nums)
    {
        int n = nums.size();
        for(int i = 0 ; i < n ; i++)
        {
            for(int j = i + 1 ; j < n  ; j++)
            {
                if(i + 1 < n &&  j + 1 < n && nums[i] + nums[i + 1] == nums[j] + nums[j + 1])
                    return true;
            }
        }
        return false;
    }
};