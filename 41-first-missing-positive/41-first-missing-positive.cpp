class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        
        int mex = 1;
        int n = nums.size();
        set<int>st;
        for(int i = 0 ; i < n ; i++)
        {
            st.insert(nums[i]);
            while(st.find(mex) != st.end()) mex++;
        }
        return mex;
    }
};