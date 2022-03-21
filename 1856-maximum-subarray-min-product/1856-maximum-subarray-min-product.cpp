class Solution 
{
public:
    int maxSumMinProduct(vector<int>& nums) 
    {
        vector<long>preSum, left(nums.size(), -1), right(nums.size(), nums.size());
        int n = nums.size();
        preSum.push_back(0);
	 
         //Getting perfix sum of given array to reduce complexity by avoiding recalculation 
         for (int i = 0; i < nums.size(); i++)
            preSum.push_back(preSum.back() + nums[i]);

        // Storing previous smaller element index in left array
         stack<int>st;
         for (int i = 0; i < nums.size(); i++) {
         while (!st.empty() && nums[i] <= nums[st.top()])
            st.pop();
         if (!st.empty())
            left[i] = st.top();
         st.push(i);
      }
       // Storing next smaller element index in right array
      st = stack<int>();
         for (int i = nums.size() - 1; i >= 0; i--) {
              while (!st.empty() && nums[i] <= nums[st.top()])
              st.pop();
        if (!st.empty())
              right[i] = st.top();
        st.push(i);
      }

      long ans = 0, mod = 1e9 + 7;

    //finally calculating the contribution of each element
      for (int i = 0; i < nums.size(); i++) {
            long t = (preSum[right[i]] - preSum[left[i] + 1]) * nums[i];
            ans = max(ans, t);
      }

      return ans % mod; 
        }
};