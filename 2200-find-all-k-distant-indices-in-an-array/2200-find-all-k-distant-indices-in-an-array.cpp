class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k)
    {
        int n = nums.size();
        vector<int> v(n + 1, 0), ans;
        for(int i = 0 ; i < n ; i++)
        {
            if(nums[i] == key)
            {
                (i - k >= 0)? v[i - k] += 1 : v[0] += 1;
                (i + k < n)? v[i + k + 1] += -1 : v[n] += -1;
            }
        }
        
        for(int i = 1 ; i < n ; i++)
            v[i] += v[i - 1];
        
        for(int i = 0 ; i < n ; i++)
            if(v[i] > 0)
                ans.push_back(i);
                
        return ans;
    }
};