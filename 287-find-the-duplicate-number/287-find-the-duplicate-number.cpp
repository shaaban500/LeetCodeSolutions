class Solution {
public:
    int findDuplicate(vector<int>& nums) {
    
        int ans;
        int f[100005]={};
        int sz = nums.size();
        
        for(int i=0 ; i<sz ; i++)
        {
            f[nums[i]]++;
            if(f[nums[i]]==2) ans = nums[i];
        }
        
        return ans;
    }
};