class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k)
    {
        int n = nums.size();
        vector<long long>prefix(n, 0);
        
        prefix[0] = nums[0];
        for(int i = 1 ; i < n ; i++)
            prefix[i] = 1LL * nums[i] + prefix[i - 1];
        
        vector<int>v;
        for(int i = 0 ; i < n ; i++)
        {
            int l = i - k;
            int r = i + k;
            
            if(l < 0 || r >= n)
            {
                v.push_back(-1);
                continue;
            }
            
            long long sum = !l ? prefix[r] : prefix[r] - prefix[l - 1];
            v.push_back( 1LL * sum / (k * 2 + 1));
        }
        
        return v;
    }
};