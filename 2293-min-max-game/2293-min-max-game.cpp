class Solution {
public:
    int minMaxGame(vector<int>& nums) 
    {
        if(nums.size() == 1)
            return nums[0];
        
        vector<vector<int>> v(12);
        for(int i = 0 ; i < nums.size() ; i++)
            v[0].push_back(nums[i]);

        int I = 0;
        int k = v[0].size();
        
        while(k > 1)
        {
            for(int i = 0, f = 1 ; i < v[I].size() ; i += 2, f = !f)
            {
                int mn = min(v[I][i], v[I][i + 1]);
                int mx  = max(v[I][i], v[I][i + 1]);
                v[I + 1].push_back((f & 1) ? mn : mx);
            }
            I++;
            k = v[I].size();
        }
        return v[I][0];
    }
};